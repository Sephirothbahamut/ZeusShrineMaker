#pragma once
#include <fstream>
#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Shrine.h"

class Interface
	{
	public:
		Interface(Shrine& shrine, Database& database) : shrine{&shrine}, database{&database}, 
			window(sf::VideoMode{1400, 1200}, "Zeus Shrine Editor", 7U)
			{
			loop(); 
			}

	private:
		sf::RenderWindow window;
		Shrine* shrine;
		Database* database;

		Building* building_hover = nullptr;
		bool mouseover_logging = true;

		void loop()
			{
			draw();
			while (window.isOpen()) { step(); }
			}

		void step()
			{
			event();
			draw();
			}

		void event()
			{
			sf::Event event;
			window.waitEvent(event);
			switch (event.type)
				{
				case sf::Event::Closed: window.close(); break;
				case sf::Event::MouseMoved: mouse_move(event.mouseMove); break;
				case sf::Event::MouseWheelScrolled: mouse_wheel(event.mouseWheelScroll); break;
				case sf::Event::KeyPressed: keyboard(event.key); break;
				}
			}

		void draw()
			{
			window.clear(sf::Color::Black);
			window.draw(*shrine);
			window.display();
			}

		// EVENTS

		void mouse_wheel(sf::Event::MouseWheelScrollEvent e)
			{
			auto view = window.getView();
			if (e.delta > 0) { view.zoom(.9); }
			else { view.zoom(1.1); }

			view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
			window.setView(view);
			}


		void mouse_move(sf::Event::MouseMoveEvent e)
			{
			auto tmp = window.mapPixelToCoords({e.x, e.y}, window.getView());

			size_t x = tmp.x / 64;
			size_t y = tmp.y / 64;


			if (x >= shrine->matrix.width() || y >= shrine->matrix.height()) { building_hover = nullptr; }
			else { building_hover = &shrine->matrix[{x, y}]; }

			if (mouseover_logging) { std::cout << "Hovering [" << x << ", " << y << "]: " << (building_hover ? building_hover->out_console() : "noone") << std::endl; }
			}

		void keyboard(sf::Event::KeyEvent e)
			{
			switch (e.code)
				{
				case sf::Keyboard::H: std::cout << R"QWE(
H: Help
Enter: Save "out.sav"
Home: Load "out.sav"

Del: Destroy
Tab: Toggle variant (Changes statues god, changes tiles decoration)
Shift: Rotate (Changes statues orientation, toggles torches on tiles)
Space: Clear overlapping components (For components larger than 1x1)
Ctrl: Toggle mouse movement coordinates logging
+: Increase elevation
-: Decrease elevation
End: Test experimental values in blocks

Create
Q: Stairs
W: Tile           (Can rotate, can toggle)
E: Statue (small) (Can rotate, can toggle)
R: Statue (large) (Can rotate, can toggle)
T: Sanctuary      (Can rotate, front-back)
Y: Sanctuary (small)
U: Altar
I: Observatory
O: Museum
P: Grand Poseidon Statue

Z: Silver
X: Copper
C: Olive
V: Vines
B: Oranges
N: Military flag  (Only Artemis and Ares)

M: Experimental. Create an empty object and wait for a number in console input. This might break the game. The purpose of this object is allowing to experiment with unknown identifiers.

					)QWE" << std::endl; break;
				case sf::Keyboard::Enter:
					{
					std::ofstream file("out.txt");
					file << shrine->out_zeus();

					std::ofstream save("out.sav");
					save << shrine->out_savefile();
					}
					break;
				case sf::Keyboard::Home:
					{
					std::ifstream file("out.sav");
					if (!file.is_open()) { throw std::runtime_error("No out.sav file found"); }
					shrine->in_savefile(file);
					}
					break;

				case sf::Keyboard::LControl: mouseover_logging = !mouseover_logging;                             break;
				case sf::Keyboard::Space:    shrine->clear_overlapping();                                        break;
				case sf::Keyboard::End:
					{
					std::cout << "First ID to check";
					int32_t index; std::cin >> index;
					std::cout << "Last ID to check";
					int32_t last; std::cin >> last;
					std::cout << "Spacing";
					int32_t spacing; std::cin >> spacing;

					shrine->matrix[0].set_type(&database->building_types[Database::Building_id::ALTAR]);
					for (int32_t y = 0; y < shrine->matrix.height(); y++)
						{
						for (int32_t x = 0; x < shrine->matrix.width(); x++)
							{
							if ((x == 0 || x == 1) && (y == 0 || y == 1)) { continue; } //Leave space for the altar; game crashes if a temple doesn't have one.

							if ((x % spacing) == 0 && (y % spacing) == 0)
								{
								shrine->matrix[{x, y}].set_type(&database->building_types[Database::Building_id::EXPERIMENTAL]);
								shrine->matrix[{x, y}].experimental_id = index++;
								}
							else { shrine->matrix[{x, y}].set_type(nullptr); }
							if (index == last) { goto OUT; }
							}
						}
				OUT:;
					}
					break;

				case sf::Keyboard::Left:
					for (int32_t y = 0; y < shrine->matrix.height(); y++)
						{
						for (int32_t x = 0; x < shrine->matrix.width() - 1; x++)
							{
							shrine->matrix[{x, y}] = shrine->matrix[{x + 1, y}];
							}
						}
					break;
				case sf::Keyboard::Right:
					for (int32_t y = 0; y < shrine->matrix.height(); y++)
						{
						for (int32_t x = shrine->matrix.width() - 1; x > 0; x--)
							{
							shrine->matrix[{x, y}] = shrine->matrix[{x - 1, y}];
							}
						}
					break;
				case sf::Keyboard::Up:
					for (int32_t y = 0; y < shrine->matrix.height() - 1; y++)
						{
						for (int32_t x = 0; x < shrine->matrix.width(); x++)
							{
							shrine->matrix[{x, y}] = shrine->matrix[{x, y + 1}];
							}
						}
					break;
				case sf::Keyboard::Down:
					for (int32_t y = shrine->matrix.height() - 1; y > 0; y--)
						{
						for (int32_t x = 0; x < shrine->matrix.width(); x++)
							{
							shrine->matrix[{x, y}] = shrine->matrix[{x, y - 1}];
							}
						}
					break;
				}

			if (building_hover)
				{
				if (building_hover->type)
					{
					switch (e.code)
						{
						case sf::Keyboard::Delete:   building_hover->set_type(nullptr);                                      break;
						case sf::Keyboard::Tab:      building_hover->set_type(database->variant(building_hover->type));      break;
						case sf::Keyboard::LShift:   building_hover->set_type(database->rotate(building_hover->type));		 break;
						}
					}

				switch (e.code)
					{
					case sf::Keyboard::Add:      building_hover->set_elevation(building_hover->elevation + 1); break;
					case sf::Keyboard::Subtract: building_hover->set_elevation(building_hover->elevation - 1); break;

					case sf::Keyboard::Q:      building_hover->set_type(&database->building_types[Database::Building_id::STAIRS]);                break;
					case sf::Keyboard::W:      building_hover->set_type(&database->building_types[Database::Building_id::SANCTUARY_TILE0]);       break;
					case sf::Keyboard::E:      building_hover->set_type(&database->building_types[Database::Building_id::SCULPTURE_ZEUS_N]);      break;
					case sf::Keyboard::R:      building_hover->set_type(&database->building_types[Database::Building_id::STATUE_OF_ZEUSN]);       break;
					case sf::Keyboard::T:      building_hover->set_type(&database->building_types[Database::Building_id::SANCTUARY_FRONT]);       break;
					case sf::Keyboard::Y:      building_hover->set_type(&database->building_types[Database::Building_id::SANCTUARY_SMALL]);       break;
					case sf::Keyboard::U:      building_hover->set_type(&database->building_types[Database::Building_id::ALTAR]);                 break;
					case sf::Keyboard::I:      building_hover->set_type(&database->building_types[Database::Building_id::OBSERVATORY]);           break;
					case sf::Keyboard::O:      building_hover->set_type(&database->building_types[Database::Building_id::MUSEUM]);                break;
					case sf::Keyboard::P:      building_hover->set_type(&database->building_types[Database::Building_id::GRAND_POSEIDON_STATUE]); break;
					
					case sf::Keyboard::Z:      building_hover->set_type(&database->building_types[Database::Building_id::SILVER_ORE]);  break;
					case sf::Keyboard::X:      building_hover->set_type(&database->building_types[Database::Building_id::COPPER_ORE]);  break;
					case sf::Keyboard::C:      building_hover->set_type(&database->building_types[Database::Building_id::OLIVE_TREES]); break;
					case sf::Keyboard::V:      building_hover->set_type(&database->building_types[Database::Building_id::GRAPE_VINES]); break;
					case sf::Keyboard::B:      building_hover->set_type(&database->building_types[Database::Building_id::ORANGE_TREE]); break;
					case sf::Keyboard::N:      building_hover->set_type(&database->building_types[Database::Building_id::SANC_FLAG_POLE]); break;

					case sf::Keyboard::M:      make_experimental(); break;
					}
				}
			}

		void make_experimental()
			{
			building_hover->set_type(&database->building_types[Database::Building_id::EXPERIMENTAL]);
			std::cin >> building_hover->experimental_id;
			}
	};

