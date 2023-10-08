#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <utils/containers/matrix_dyn.h>

#include "Database.h"

inline sf::Font font;
inline sf::Text default_text;

class Building : public sf::Drawable
	{
	public:
		Building() = default;
		Building& operator=(const Building& copy)
			{
			set_elevation(copy.elevation);
			set_type(copy.type);
			order = copy.order;
			experimental_id = copy.experimental_id;

			return *this;
			}

		int32_t elevation{0};
		int32_t order{-1};
		sf::Vector2u pos{0, 0};
		Database::Building* type{nullptr};
		sf::Text text{default_text};
		int32_t experimental_id{0};

		void set_type(Database::Building* new_type)
			{
			type = new_type;
			if (type)
				{
				sprite = type->sprite;
				sprite.setPosition(static_cast<float>(pos.x * 64), static_cast<float>(pos.y * 64));
				}
			}

		void set_elevation(int32_t new_elevation)
			{
			elevation = new_elevation;
			text.setString(std::to_string(elevation));
			}

		void set_position(sf::Vector2u new_pos)
			{
			pos = new_pos;
			text.setPosition(pos.x * 64, pos.y * 64);
			sprite.setPosition(text.getPosition());
			}

		std::string out_console() const noexcept
			{
			if (!type) { return "empty"; }

			std::stringstream ss;
			ss << "Elevation " << elevation << ", Part ID: " << type->id << " Part name: " << type->name;
			if (type->id == Database::Building_id::EXPERIMENTAL) { ss << " - experimental id: " << experimental_id; }
			return ss.str();
			}

		std::string out_zeus() const noexcept
			{
			if (!type) { return ""; }

			std::stringstream ss;
			ss << "{" << pos.x << ", " << pos.y << ", ";
			if (type->id != Database::Building_id::EXPERIMENTAL) { ss << type->id; }
			else { ss << experimental_id; }

			ss << ", " << elevation;
			if (order != -1) { ss << ", " << order; }
			ss << ",},";
			return ss.str();
			}

		std::string out_savefile() const noexcept
			{
			std::stringstream ss;
			ss << pos.x << ' ' << pos.y << ' ';

			if (type)
				{
				if (type->id != Database::Building_id::EXPERIMENTAL) { ss << type->id; }
				else { ss << experimental_id; }
				}
			else { ss << Database::Building_id::SKIP; }

			ss << ' ' << elevation << ' ' << order;
			return ss.str();
			}

		void from_file(Database& database, std::ifstream& file)
			{
			sf::Vector2u p;
			file >> p.x >> p.y;
			set_position(p);

			int32_t tmp_id; file >> tmp_id; 
			if (static_cast<Database::Building_id>(tmp_id) != Database::Building_id::SKIP)
				{
				auto it = database.building_types.find(tmp_id);
				if (it != database.building_types.end()) { set_type(&(it->second)); }
				else { set_type(&database.building_types[Database::Building_id::EXPERIMENTAL]); experimental_id = tmp_id; }
				}

			int32_t e;
			file >> e >> order;
			set_elevation(e);
			}

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
			{
			if (type) { target.draw(sprite, states); target.draw(text, states); }

			}

	private:
		sf::Sprite sprite;
	};

class Shrine : public sf::Drawable
	{
	public:
		Shrine(Database& database, sf::Vector2u size) : database(&database), matrix(size.x, size.y)
			{
			for (uint32_t y = 0; y < size.y; y++)
				{
				for (uint32_t x = 0; x < size.x; x++)
					{
					matrix[{x, y}].set_position({x, y});
					}
				}
			}

		std::string out_zeus()
			{
			std::stringstream ss;

			for (const auto& element : matrix) { if (element.type != nullptr) { ss << element.out_zeus() << '\n'; } }

			return ss.str();
			}

		std::string out_savefile() const noexcept
			{
			std::stringstream ss;
			ss << matrix.width() << ' ' << matrix.height() << '\n';

			for (const auto& element : matrix) { ss << element.out_savefile() << '\n'; }
			return ss.str();
			}

		void in_savefile(std::ifstream& file)
			{
			int32_t width, height; 
			file >> width; file >> height;

			for (int32_t y = 0; y < height; y++)
				{
				for (int32_t x = 0; x < width; x++)
					{
					matrix[{x, y}].from_file(*database, file);
					}
				}
			}

		void clear_overlapping()
			{
			for (const auto& element : matrix)
				{
				if (element.type != nullptr && element.type->size != sf::Vector2u{1, 1})
					{
					clear_overlapping(element.pos, element.type->size);
					}
				}
			}

		utils::containers::matrix_dyn<Building> matrix;


		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
			{
			for (const auto& element : matrix) { target.draw(element, states); }
			}

	private:
		Database* database;

		void clear_overlapping(sf::Vector2u pos, sf::Vector2u size)
			{
			auto tmp = matrix[{pos.x, pos.y}];

			for (size_t y = pos.y; y < pos.y + size.y; y++)
				{
				for (size_t x = pos.x; x < pos.x + size.x; x++)
					{
					matrix[{x, y}].type = nullptr;
					}
				}

			matrix[{pos.x, pos.y}] = tmp;
			}
	};