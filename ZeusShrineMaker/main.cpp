#include <iostream>

#include "Database.h"
#include "Shrine.h"
#include "Interface.h"

int main()
	{
	try
		{
		if (!font.loadFromFile("Arial.ttf")) { throw std::runtime_error("Could not load font Arial.ttf"); }

		default_text = sf::Text{"0", font, 16u};
		default_text.setFillColor({0, 150, 100});
		default_text.setOrigin({-4, -4});

		Database database;
		Shrine shrine(database, {40, 30});

		Interface interface(shrine, database);
		}
	catch (std::runtime_error e) { std::cout << e.what() << std::endl; }

	return 0;
	}