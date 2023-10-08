#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "Support.h"

enum class God_id
	{	
	Zeus, Poseidon, Hades, Demeter, Athena, Artemis, Apollo, Ares, Hephaestus, Aphrodite, Hermes, Dionysus, Atlas, Hera
	};

enum Building_id : int32_t
	{
	//Base Parts
	SANCTUARY_FRONT = 0,
	SANCTUARY_BACK = 1,
	ALTAR = 2,
	PALACE_FRONT = 3,
	PALACE_BACK = 4,
	PALACE_FLAG_POLE = 5,
	PALACE_CORNER = 6,
	SCULPTURE_ZEUS_N = 7,
	SCULPTURE_ZEUS_E = 8,
	SCULPTURE_ZEUS_S = 9,
	SCULPTURE_ZEUS_W = 10,
	SCULPTURE_POSEIDON_N = 11,
	SCULPTURE_POSEIDON_E = 12,
	SCULPTURE_POSEIDON_S = 13,
	SCULPTURE_POSEIDON_W = 14,
	SCULPTURE_HADES_N = 15,
	SCULPTURE_HADES_E = 16,
	SCULPTURE_HADES_S = 17,
	SCULPTURE_HADES_W = 18,
	SCULPTURE_DEMETER_N = 19,
	SCULPTURE_DEMETER_E = 20,
	SCULPTURE_DEMETER_S = 21,
	SCULPTURE_DEMETER_W = 22,
	SCULPTURE_ATHENA_N = 23,
	SCULPTURE_ATHENA_E = 24,
	SCULPTURE_ATHENA_S = 25,
	SCULPTURE_ATHENA_W = 26,
	SCULPTURE_ARTEMIS_N = 27,
	SCULPTURE_ARTEMIS_E = 28,
	SCULPTURE_ARTEMIS_S = 29,
	SCULPTURE_ARTEMIS_W = 30,
	SCULPTURE_APOLLO_N = 31,
	SCULPTURE_APOLLO_E = 32,
	SCULPTURE_APOLLO_S = 33,
	SCULPTURE_APOLLO_W = 34,
	SCULPTURE_ARES_N = 35,
	SCULPTURE_ARES_E = 36,
	SCULPTURE_ARES_S = 37,
	SCULPTURE_ARES_W = 38,
	SCULPTURE_HEPHAESTUS_N = 39,
	SCULPTURE_HEPHAESTUS_E = 40,
	SCULPTURE_HEPHAESTUS_S = 41,
	SCULPTURE_HEPHAESTUS_W = 42,
	SCULPTURE_APHRODITE_N = 43,
	SCULPTURE_APHRODITE_E = 44,
	SCULPTURE_APHRODITE_S = 45,
	SCULPTURE_APHRODITE_W = 46,
	SCULPTURE_HERMES_N = 47,
	SCULPTURE_HERMES_E = 48,
	SCULPTURE_HERMES_S = 49,
	SCULPTURE_HERMES_W = 50,
	SCULPTURE_DIONYSUS_N = 51,
	SCULPTURE_DIONYSUS_E = 52,
	SCULPTURE_DIONYSUS_S = 53,
	SCULPTURE_DIONYSUS_W = 54,
	SANCTUARY_TILE0 = 55,
	SANCTUARY_TILE1 = 56,
	SANCTUARY_TILE2 = 57,
	SANCTUARY_TILE3 = 58,
	SANCTUARY_TILE4 = 59,
	SANCTUARY_TILE5 = 60,
	STATUE_OF_ZEUSN = 61,
	STATUE_OF_ZEUSE = 62,
	STATUE_OF_ZEUSS = 63,
	STATUE_OF_ZEUSW = 64,
	STATUE_OF_POSEIDONN = 65,
	STATUE_OF_POSEIDONE = 66,
	STATUE_OF_POSEIDONS = 67,
	STATUE_OF_POSEIDONW = 68,
	STATUE_OF_HADESN = 69,
	STATUE_OF_HADESE = 70,
	STATUE_OF_HADESS = 71,
	STATUE_OF_HADESW = 72,
	STATUE_OF_DEMETERN = 73,
	STATUE_OF_DEMETERE = 74,
	STATUE_OF_DEMETERS = 75,
	STATUE_OF_DEMETERW = 76,
	STATUE_OF_ATHENAN = 77,
	STATUE_OF_ATHENAE = 78,
	STATUE_OF_ATHENAS = 79,
	STATUE_OF_ATHENAW = 80,
	STATUE_OF_ARTEMISN = 81,
	STATUE_OF_ARTEMISE = 82,
	STATUE_OF_ARTEMISS = 83,
	STATUE_OF_ARTEMISW = 84,
	STATUE_OF_APOLLON = 85,
	STATUE_OF_APOLLOE = 86,
	STATUE_OF_APOLLOS = 87,
	STATUE_OF_APOLLOW = 88,
	STATUE_OF_ARESN = 89,
	STATUE_OF_ARESE = 90,
	STATUE_OF_ARESS = 91,
	STATUE_OF_ARESW = 92,
	STATUE_OF_HEPHAESTUSN = 93,
	STATUE_OF_HEPHAESTUSE = 94,
	STATUE_OF_HEPHAESTUSS = 95,
	STATUE_OF_HEPHAESTUSW = 96,
	STATUE_OF_APHRODITEN = 97,
	STATUE_OF_APHRODITEE = 98,
	STATUE_OF_APHRODITES = 99,
	STATUE_OF_APHRODITEW = 100,
	STATUE_OF_HERMESN = 101,
	STATUE_OF_HERMESE = 102,
	STATUE_OF_HERMESS = 103,
	STATUE_OF_HERMESW = 104,
	STATUE_OF_DIONYSUSN = 105,
	STATUE_OF_DIONYSUSE = 106,
	STATUE_OF_DIONYSUSS = 107,
	STATUE_OF_DIONYSUSW = 108,
	SANC_FLAG_POLE = 109,

	FIREPOT_TILE0 = 111,
	FIREPOT_TILE1 = 112,
	FIREPOT_TILE2 = 113,
	FIREPOT_TILE3 = 114,
	FIREPOT_TILE4 = 115,
	FIREPOT_TILE5 = 116,

	//Base Buildings?

	//Expansion Parts
	SCULPTURE_ATLAS_N = 137,
	SCULPTURE_ATLAS_E = 138,
	SCULPTURE_ATLAS_S = 139,
	SCULPTURE_ATLAS_W = 140,

	SCULPTURE_HERA_N = 133,
	SCULPTURE_HERA_E = 134,
	SCULPTURE_HERA_S = 135,
	SCULPTURE_HERA_W = 136,

	STATUE_OF_ATLASN = 129,
	STATUE_OF_ATLASE = 130,
	STATUE_OF_ATLASS = 131,
	STATUE_OF_ATLASW = 132,

	STATUE_OF_HERAN = 125,
	STATUE_OF_HERAE = 126,
	STATUE_OF_HERAS = 127,
	STATUE_OF_HERAW = 128,

	//Expansion Buildings
	OBSERVATORY = 149,
	MUSEUM = 150,

	//Resources
	STAIRS = 1000, //Not specified but used in default temples on stairs

	SILVER_ORE = 1001,
	OLIVE_TREES = 1002,
	COPPER_ORE = 1003,
	GRAPE_VINES = 1004,

	//No game entity
	SKIP = 99999,
	};

namespace Color_id
	{
	inline const sf::Color SANCTUARY_FRONT{  0,   0, 255};
	inline const sf::Color SANCTUARY_BACK {  0,  50, 255};
	inline const sf::Color ALTAR          {255,   0,   0};
	
	inline const sf::Color STATUE_LARGE_N  {255, 255,   0};
	inline const sf::Color STATUE_LARGE_E  {255, 255,  80};
	inline const sf::Color STATUE_LARGE_S  {255, 255, 160};
	inline const sf::Color STATUE_LARGE_W  {255, 255, 200};
	inline const sf::Color STATUE_SMALL_N  {255, 106,   0};
	inline const sf::Color STATUE_SMALL_E  {255, 106,  80};
	inline const sf::Color STATUE_SMALL_S  {255, 106, 160};
	inline const sf::Color STATUE_SMALL_W  {255, 106, 200};
	
	inline const sf::Color SANCTUARY_TILE0 {255, 255, 255};
	inline const sf::Color SANCTUARY_TILE1 {200, 255, 255};
	inline const sf::Color SANCTUARY_TILE2 {255, 200, 255};
	inline const sf::Color SANCTUARY_TILE3 {255, 255, 200};
	inline const sf::Color SANCTUARY_TILE4 {200, 200, 255};
	inline const sf::Color SANCTUARY_TILE5 {255, 200, 200};

	inline const sf::Color FIREPOT_TILE0   {255, 155, 155};
	inline const sf::Color FIREPOT_TILE1   {200, 155, 155};
	inline const sf::Color FIREPOT_TILE2   {255, 100, 155};
	inline const sf::Color FIREPOT_TILE3   {255, 155, 100};
	inline const sf::Color FIREPOT_TILE4   {200, 100, 155};
	inline const sf::Color FIREPOT_TILE5   {255, 100, 100};

	inline const sf::Color STAIRS          {  0,   0,   0};
	inline const sf::Color OLIVE_TREES     {  0, 100,   0};
	inline const sf::Color GRAPE_VINES     {100, 100,   0};
	}

namespace std
	{
	template <>
	struct hash<sf::Color>
		{
		std::uint32_t operator()(const sf::Color& color) const
			{
			return color.toInteger();
			}
		};
	}

inline std::unordered_map<sf::Color, Building_id> color_map
	{
		{Color_id::SANCTUARY_FRONT,  Building_id::SANCTUARY_FRONT},
		{Color_id::SANCTUARY_BACK,   Building_id::SANCTUARY_BACK},
		{Color_id::ALTAR,            Building_id::ALTAR},
		{Color_id::STAIRS,           Building_id::STAIRS},

		{Color_id::SANCTUARY_TILE0,  Building_id::SANCTUARY_TILE0},
		{Color_id::SANCTUARY_TILE1,  Building_id::SANCTUARY_TILE1},
		{Color_id::SANCTUARY_TILE2,  Building_id::SANCTUARY_TILE2},
		{Color_id::SANCTUARY_TILE3,  Building_id::SANCTUARY_TILE3},
		{Color_id::SANCTUARY_TILE4,  Building_id::SANCTUARY_TILE4},
		{Color_id::SANCTUARY_TILE5,  Building_id::SANCTUARY_TILE5},

		{Color_id::FIREPOT_TILE0,    Building_id::FIREPOT_TILE0},
		{Color_id::FIREPOT_TILE1,    Building_id::FIREPOT_TILE1},
		{Color_id::FIREPOT_TILE2,    Building_id::FIREPOT_TILE2},
		{Color_id::FIREPOT_TILE3,    Building_id::FIREPOT_TILE3},
		{Color_id::FIREPOT_TILE4,    Building_id::FIREPOT_TILE4},
		{Color_id::FIREPOT_TILE5,    Building_id::FIREPOT_TILE5},

		{Color_id::OLIVE_TREES,      Building_id::OLIVE_TREES},
	};

Building_id get_building_id(sf::Color color, God_id god = God_id::Zeus)
	{
	if (color == sf::Color::Transparent) { return Building_id::SKIP; }

	color.a = 255;
	if (color == Color_id::STATUE_LARGE_N ||
		color == Color_id::STATUE_LARGE_E ||
		color == Color_id::STATUE_LARGE_S ||
		color == Color_id::STATUE_LARGE_W)
		{
		Building_id building;
		switch (god)
			{
			case God_id::Zeus:		building = Building_id::STATUE_OF_ZEUSN;       break;
			case God_id::Poseidon:	building = Building_id::STATUE_OF_POSEIDONN;   break;
			case God_id::Hades:		building = Building_id::STATUE_OF_HADESN;      break;
			case God_id::Demeter:	building = Building_id::STATUE_OF_DEMETERN;    break;
			case God_id::Athena:	building = Building_id::STATUE_OF_ATHENAN;     break;
			case God_id::Artemis:	building = Building_id::STATUE_OF_ARTEMISN;    break;
			case God_id::Apollo:	building = Building_id::STATUE_OF_APOLLON;     break;
			case God_id::Ares:		building = Building_id::STATUE_OF_ARESN;       break;
			case God_id::Hephaestus:building = Building_id::STATUE_OF_HEPHAESTUSN; break;
			case God_id::Aphrodite:	building = Building_id::STATUE_OF_APHRODITEN;  break;
			case God_id::Hermes:	building = Building_id::STATUE_OF_HERMESN;     break;
			case God_id::Dionysus:	building = Building_id::STATUE_OF_DIONYSUSE;   break;
			case God_id::Atlas:		building = Building_id::STATUE_OF_ATLASN;      break;
			case God_id::Hera:		building = Building_id::STATUE_OF_HERAN;       break;
			}

		/**/ if (color == Color_id::STATUE_LARGE_N) { return Building_id{building + 0}; }
		else if (color == Color_id::STATUE_LARGE_E) { return Building_id{building + 1}; }
		else if (color == Color_id::STATUE_LARGE_S) { return Building_id{building + 2}; }
		else if (color == Color_id::STATUE_LARGE_W) { return Building_id{building + 3}; }
		}
	else
	if (color == Color_id::STATUE_SMALL_N ||
		color == Color_id::STATUE_SMALL_E ||
		color == Color_id::STATUE_SMALL_S ||
		color == Color_id::STATUE_SMALL_W)
		{
		Building_id building;
		switch (god)
			{
			case God_id::Zeus:		building = Building_id::SCULPTURE_ZEUS_N;       break;
			case God_id::Poseidon:	building = Building_id::SCULPTURE_POSEIDON_N;   break;
			case God_id::Hades:		building = Building_id::SCULPTURE_HADES_N;      break;
			case God_id::Demeter:	building = Building_id::SCULPTURE_DEMETER_N;    break;
			case God_id::Athena:	building = Building_id::SCULPTURE_ATHENA_N;     break;
			case God_id::Artemis:	building = Building_id::SCULPTURE_ARTEMIS_N;    break;
			case God_id::Apollo:	building = Building_id::SCULPTURE_APOLLO_N;     break;
			case God_id::Ares:		building = Building_id::SCULPTURE_ARES_N;       break;
			case God_id::Hephaestus:building = Building_id::SCULPTURE_HEPHAESTUS_N; break;
			case God_id::Aphrodite:	building = Building_id::SCULPTURE_APHRODITE_N;  break;
			case God_id::Hermes:	building = Building_id::SCULPTURE_HERMES_N;     break;
			case God_id::Dionysus:	building = Building_id::SCULPTURE_DIONYSUS_E;   break;
			case God_id::Atlas:		building = Building_id::SCULPTURE_ATLAS_N;      break;
			case God_id::Hera:		building = Building_id::SCULPTURE_HERA_N;       break;
			}

		/**/ if (color == Color_id::STATUE_SMALL_N) { return Building_id{building + 0}; }
		else if (color == Color_id::STATUE_SMALL_E) { return Building_id{building + 1}; }
		else if (color == Color_id::STATUE_SMALL_S) { return Building_id{building + 2}; }
		else if (color == Color_id::STATUE_SMALL_W) { return Building_id{building + 3}; }
		}
	else
		{
		auto it = color_map.find(color);
		if (it == color_map.end()) { throw std::runtime_error("No building associated with color " + to_string(color)); }

		return it->second;
		}
	}
