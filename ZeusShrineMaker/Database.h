#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>


class Database
	{
	public:
		enum class God_id
			{
			none, Zeus, Poseidon, Hades, Demeter, Athena, Artemis, Apollo, Ares, Hephaestus, Aphrodite, Hermes, Dionysus, Atlas, Hera
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

			SANCTUARY_SMALL = 110,

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
			GRAND_POSEIDON_STATUE = 151,
			SANCTUARY_FRONT_HORIZONTAL = 158,
			SANCTUARY_BACK_HORIZONTAL = 159,

			//Other
			SANC_FLAG_POLE = 109,

			//Resources
			SILVER_ORE = 1001,
			OLIVE_TREES = 1002,
			COPPER_ORE = 1003,
			GRAPE_VINES = 1004,
			ORANGE_TREE = 1005,

			//Not specified but used in default temples on stairs
			STAIRS = 1000,

			//No game entity
			SKIP = 99999,
			EXPERIMENTAL = 99990,

			//DISCOVERED
			WOOD_BUILD_TILE = 1006
			};
//CRASHES:
/*
1007-1013
*/


		struct Building
			{
			public:
				enum Type { tile, statue_small, statue_large, building, sanctuary, resource, other, experimental };
				enum Dir { none, n, e, s, w, _4, _5 };

				Building() { throw std::logic_error("This should never be called"); };
				Building(Type type, int32_t id, const char* name, sf::Vector2u pos, sf::Vector2u size, const sf::Texture& texture, Dir dir = Dir::n, Database::God_id god = Database::God_id::Zeus)
					: type{type}, id{id}, name{name}, size{size}, sprite{texture, rect(pos, size)}, dir{dir}, god{god}
					{}

				Type type;
				int32_t id;
				const char* name;
				sf::Vector2u size;
				sf::Sprite sprite;
				Dir dir = Dir::none;;
				Database::God_id god = Database::God_id::none;

			private:
				sf::IntRect rect(sf::Vector2u pos, sf::Vector2u size)
					{
					return {static_cast<int>(pos.x * 64), static_cast<int>(pos.y * 64), static_cast<int>(size.x * 64), static_cast<int>(size.y * 64)};
					}
			};

		sf::Texture spritesheet;
		std::unordered_map<int32_t, Building> building_types;


		Database()
			{
			if (!spritesheet.loadFromFile("Spritesheet.png")) { throw std::runtime_error("Failed to load main spritesheet"); }
			
			//Tiles
			if (true)
				{
				add_building_type(Building::Type::other, Building_id::STAIRS, "STAIRS", { 1, 0}, {1, 1});

				add_building_type(Building::Type::tile, Building_id::SANCTUARY_TILE0, "SANCTUARY_TILE0,", { 2, 0}, {1, 1}, Building::Dir::n , God_id::none);
				add_building_type(Building::Type::tile, Building_id::SANCTUARY_TILE1, "SANCTUARY_TILE1,", { 3, 0}, {1, 1}, Building::Dir::e , God_id::none);
				add_building_type(Building::Type::tile, Building_id::SANCTUARY_TILE2, "SANCTUARY_TILE2,", { 4, 0}, {1, 1}, Building::Dir::s , God_id::none);
				add_building_type(Building::Type::tile, Building_id::SANCTUARY_TILE3, "SANCTUARY_TILE3,", { 5, 0}, {1, 1}, Building::Dir::w , God_id::none);
				add_building_type(Building::Type::tile, Building_id::SANCTUARY_TILE4, "SANCTUARY_TILE4,", { 6, 0}, {1, 1}, Building::Dir::_4, God_id::none);
				add_building_type(Building::Type::tile, Building_id::SANCTUARY_TILE5, "SANCTUARY_TILE5,", { 7, 0}, {1, 1}, Building::Dir::_5, God_id::none);
				add_building_type(Building::Type::tile, Building_id::FIREPOT_TILE0,   "FIREPOT_TILE0",    { 8, 0}, {1, 1}, Building::Dir::n , God_id::Zeus);
				add_building_type(Building::Type::tile, Building_id::FIREPOT_TILE1,   "FIREPOT_TILE1",    { 9, 0}, {1, 1}, Building::Dir::e , God_id::Zeus);
				add_building_type(Building::Type::tile, Building_id::FIREPOT_TILE2,   "FIREPOT_TILE2",    {10, 0}, {1, 1}, Building::Dir::s , God_id::Zeus);
				add_building_type(Building::Type::tile, Building_id::FIREPOT_TILE3,   "FIREPOT_TILE3",    {11, 0}, {1, 1}, Building::Dir::w , God_id::Zeus);
				add_building_type(Building::Type::tile, Building_id::FIREPOT_TILE4,   "FIREPOT_TILE4",    {12, 0}, {1, 1}, Building::Dir::_4, God_id::Zeus);
				add_building_type(Building::Type::tile, Building_id::FIREPOT_TILE5,   "FIREPOT_TILE5",    {13, 0}, {1, 1}, Building::Dir::_5, God_id::Zeus);
				}
			
			//Statues (small)
			if(true)
				{
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ZEUS_N,       "SCULPTURE_ZEUS_N",       {  0, 1}, {1, 1}, Building::Dir::n, God_id::Zeus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ZEUS_E,       "SCULPTURE_ZEUS_E",       {  0, 2}, {1, 1}, Building::Dir::e, God_id::Zeus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ZEUS_S,       "SCULPTURE_ZEUS_S",       {  0, 3}, {1, 1}, Building::Dir::s, God_id::Zeus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ZEUS_W,       "SCULPTURE_ZEUS_W",       {  0, 4}, {1, 1}, Building::Dir::w, God_id::Zeus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_POSEIDON_N,   "SCULPTURE_POSEIDON_N",   {  1, 1}, {1, 1}, Building::Dir::n, God_id::Poseidon);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_POSEIDON_E,   "SCULPTURE_POSEIDON_E",   {  1, 2}, {1, 1}, Building::Dir::e, God_id::Poseidon);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_POSEIDON_S,   "SCULPTURE_POSEIDON_S",   {  1, 3}, {1, 1}, Building::Dir::s, God_id::Poseidon);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_POSEIDON_W,   "SCULPTURE_POSEIDON_W",   {  1, 4}, {1, 1}, Building::Dir::w, God_id::Poseidon);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HADES_N,      "SCULPTURE_HADES_N",      {  2, 1}, {1, 1}, Building::Dir::n, God_id::Hades);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HADES_E,      "SCULPTURE_HADES_E",      {  2, 2}, {1, 1}, Building::Dir::e, God_id::Hades);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HADES_S,      "SCULPTURE_HADES_S",      {  2, 3}, {1, 1}, Building::Dir::s, God_id::Hades);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HADES_W,      "SCULPTURE_HADES_W",      {  2, 4}, {1, 1}, Building::Dir::w, God_id::Hades);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_DEMETER_N,    "SCULPTURE_DEMETER_N",    {  3, 1}, {1, 1}, Building::Dir::n, God_id::Demeter);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_DEMETER_E,    "SCULPTURE_DEMETER_E",    {  3, 2}, {1, 1}, Building::Dir::e, God_id::Demeter);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_DEMETER_S,    "SCULPTURE_DEMETER_S",    {  3, 3}, {1, 1}, Building::Dir::s, God_id::Demeter);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_DEMETER_W,    "SCULPTURE_DEMETER_W",    {  3, 4}, {1, 1}, Building::Dir::w, God_id::Demeter);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ATHENA_N,     "SCULPTURE_ATHENA_N",     {  4, 1}, {1, 1}, Building::Dir::n, God_id::Athena);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ATHENA_E,     "SCULPTURE_ATHENA_E",     {  4, 2}, {1, 1}, Building::Dir::e, God_id::Athena);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ATHENA_S,     "SCULPTURE_ATHENA_S",     {  4, 3}, {1, 1}, Building::Dir::s, God_id::Athena);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ATHENA_W,     "SCULPTURE_ATHENA_W",     {  4, 4}, {1, 1}, Building::Dir::w, God_id::Athena);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ARTEMIS_N,    "SCULPTURE_ARTEMIS_N",    {  5, 1}, {1, 1}, Building::Dir::n, God_id::Artemis);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ARTEMIS_E,    "SCULPTURE_ARTEMIS_E",    {  5, 2}, {1, 1}, Building::Dir::e, God_id::Artemis);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ARTEMIS_S,    "SCULPTURE_ARTEMIS_S",    {  5, 3}, {1, 1}, Building::Dir::s, God_id::Artemis);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ARTEMIS_W,    "SCULPTURE_ARTEMIS_W",    {  5, 4}, {1, 1}, Building::Dir::w, God_id::Artemis);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_APOLLO_N,     "SCULPTURE_APOLLO_N",     {  6, 1}, {1, 1}, Building::Dir::n, God_id::Apollo);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_APOLLO_E,     "SCULPTURE_APOLLO_E",     {  6, 2}, {1, 1}, Building::Dir::e, God_id::Apollo);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_APOLLO_S,     "SCULPTURE_APOLLO_S",     {  6, 3}, {1, 1}, Building::Dir::s, God_id::Apollo);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_APOLLO_W,     "SCULPTURE_APOLLO_W",     {  6, 4}, {1, 1}, Building::Dir::w, God_id::Apollo);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ARES_N,       "SCULPTURE_ARES_N",       {  7, 1}, {1, 1}, Building::Dir::n, God_id::Ares);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ARES_E,       "SCULPTURE_ARES_E",       {  7, 2}, {1, 1}, Building::Dir::e, God_id::Ares);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ARES_S,       "SCULPTURE_ARES_S",       {  7, 3}, {1, 1}, Building::Dir::s, God_id::Ares);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ARES_W,       "SCULPTURE_ARES_W",       {  7, 4}, {1, 1}, Building::Dir::w, God_id::Ares);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HEPHAESTUS_N, "SCULPTURE_HEPHAESTUSN", {  8, 1}, {1, 1}, Building::Dir::n, God_id::Hephaestus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HEPHAESTUS_E, "SCULPTURE_HEPHAESTUSE", {  8, 2}, {1, 1}, Building::Dir::e, God_id::Hephaestus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HEPHAESTUS_S, "SCULPTURE_HEPHAESTUSS", {  8, 3}, {1, 1}, Building::Dir::s, God_id::Hephaestus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HEPHAESTUS_W, "SCULPTURE_HEPHAESTUSW", {  8, 4}, {1, 1}, Building::Dir::w, God_id::Hephaestus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_APHRODITE_N,  "SCULPTURE_APHRODITE_N",  {  9, 1}, {1, 1}, Building::Dir::n, God_id::Aphrodite);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_APHRODITE_E,  "SCULPTURE_APHRODITE_E",  {  9, 2}, {1, 1}, Building::Dir::e, God_id::Aphrodite);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_APHRODITE_S,  "SCULPTURE_APHRODITE_S",  {  9, 3}, {1, 1}, Building::Dir::s, God_id::Aphrodite);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_APHRODITE_W,  "SCULPTURE_APHRODITE_W",  {  9, 4}, {1, 1}, Building::Dir::w, God_id::Aphrodite);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HERMES_N,     "SCULPTURE_HERMES_N",     { 10, 1}, {1, 1}, Building::Dir::n, God_id::Hermes);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HERMES_E,     "SCULPTURE_HERMES_E",     { 10, 2}, {1, 1}, Building::Dir::e, God_id::Hermes);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HERMES_S,     "SCULPTURE_HERMES_S",     { 10, 3}, {1, 1}, Building::Dir::s, God_id::Hermes);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HERMES_W,     "SCULPTURE_HERMES_W",     { 10, 4}, {1, 1}, Building::Dir::w, God_id::Hermes);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_DIONYSUS_N,   "SCULPTURE_DIONYSUS_N",   { 11, 1}, {1, 1}, Building::Dir::n, God_id::Dionysus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_DIONYSUS_E,   "SCULPTURE_DIONYSUS_E",   { 11, 2}, {1, 1}, Building::Dir::e, God_id::Dionysus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_DIONYSUS_S,   "SCULPTURE_DIONYSUS_S",   { 11, 3}, {1, 1}, Building::Dir::s, God_id::Dionysus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_DIONYSUS_W,   "SCULPTURE_DIONYSUS_W",   { 11, 4}, {1, 1}, Building::Dir::w, God_id::Dionysus);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ATLAS_N,      "SCULPTURE_ATLAS_N",      { 12, 1}, {1, 1}, Building::Dir::n, God_id::Atlas);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ATLAS_E,      "SCULPTURE_ATLAS_E",      { 12, 2}, {1, 1}, Building::Dir::e, God_id::Atlas);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ATLAS_S,      "SCULPTURE_ATLAS_S",      { 12, 3}, {1, 1}, Building::Dir::s, God_id::Atlas);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_ATLAS_W,      "SCULPTURE_ATLAS_W",      { 12, 4}, {1, 1}, Building::Dir::w, God_id::Atlas);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HERA_N,       "SCULPTURE_HERA_N",       { 13, 1}, {1, 1}, Building::Dir::n, God_id::Hera);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HERA_E,       "SCULPTURE_HERA_E",       { 13, 2}, {1, 1}, Building::Dir::e, God_id::Hera);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HERA_S,       "SCULPTURE_HERA_S",       { 13, 3}, {1, 1}, Building::Dir::s, God_id::Hera);
				add_building_type(Building::Type::statue_small, Building_id::SCULPTURE_HERA_W,       "SCULPTURE_HERA_W",       { 13, 4}, {1, 1}, Building::Dir::w, God_id::Hera);
				}
			
			//Statues (large)
			if(true)
				{
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ZEUSN,       "STATUE_OF_ZEUSN",       {  0,  5}, {2, 2}, Building::Dir::n, God_id::Zeus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ZEUSE,       "STATUE_OF_ZEUSE",       {  0,  7}, {2, 2}, Building::Dir::e, God_id::Zeus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ZEUSS,       "STATUE_OF_ZEUSS",       {  0,  9}, {2, 2}, Building::Dir::s, God_id::Zeus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ZEUSW,       "STATUE_OF_ZEUSW",       {  0, 11}, {2, 2}, Building::Dir::w, God_id::Zeus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_POSEIDONN,   "STATUE_OF_POSEIDONN",   {  2,  5}, {2, 2}, Building::Dir::n, God_id::Poseidon);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_POSEIDONE,   "STATUE_OF_POSEIDONE",   {  2,  7}, {2, 2}, Building::Dir::e, God_id::Poseidon);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_POSEIDONS,   "STATUE_OF_POSEIDONS",   {  2,  9}, {2, 2}, Building::Dir::s, God_id::Poseidon);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_POSEIDONW,   "STATUE_OF_POSEIDONW",   {  2, 11}, {2, 2}, Building::Dir::w, God_id::Poseidon);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HADESN,      "STATUE_OF_HADESN",      {  4,  5}, {2, 2}, Building::Dir::n, God_id::Hades);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HADESE,      "STATUE_OF_HADESE",      {  4,  7}, {2, 2}, Building::Dir::e, God_id::Hades);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HADESS,      "STATUE_OF_HADESS",      {  4,  9}, {2, 2}, Building::Dir::s, God_id::Hades);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HADESW,      "STATUE_OF_HADESW",      {  4, 11}, {2, 2}, Building::Dir::w, God_id::Hades);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_DEMETERN,    "STATUE_OF_DEMETERN",    {  6,  5}, {2, 2}, Building::Dir::n, God_id::Demeter);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_DEMETERE,    "STATUE_OF_DEMETERE",    {  6,  7}, {2, 2}, Building::Dir::e, God_id::Demeter);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_DEMETERS,    "STATUE_OF_DEMETERS",    {  6,  9}, {2, 2}, Building::Dir::s, God_id::Demeter);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_DEMETERW,    "STATUE_OF_DEMETERW",    {  6, 11}, {2, 2}, Building::Dir::w, God_id::Demeter);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ATHENAN,     "STATUE_OF_ATHENAN",     {  8,  5}, {2, 2}, Building::Dir::n, God_id::Athena);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ATHENAE,     "STATUE_OF_ATHENAE",     {  8,  7}, {2, 2}, Building::Dir::e, God_id::Athena);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ATHENAS,     "STATUE_OF_ATHENAS",     {  8,  9}, {2, 2}, Building::Dir::s, God_id::Athena);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ATHENAW,     "STATUE_OF_ATHENAW",     {  8, 11}, {2, 2}, Building::Dir::w, God_id::Athena);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ARTEMISN,    "STATUE_OF_ARTEMISN",    { 10,  5}, {2, 2}, Building::Dir::n, God_id::Artemis);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ARTEMISE,    "STATUE_OF_ARTEMISE",    { 10,  7}, {2, 2}, Building::Dir::e, God_id::Artemis);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ARTEMISS,    "STATUE_OF_ARTEMISS",    { 10,  9}, {2, 2}, Building::Dir::s, God_id::Artemis);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ARTEMISW,    "STATUE_OF_ARTEMISW",    { 10, 11}, {2, 2}, Building::Dir::w, God_id::Artemis);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_APOLLON,     "STATUE_OF_APOLLON",     { 12,  5}, {2, 2}, Building::Dir::n, God_id::Apollo);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_APOLLOE,     "STATUE_OF_APOLLOE",     { 12,  7}, {2, 2}, Building::Dir::e, God_id::Apollo);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_APOLLOS,     "STATUE_OF_APOLLOS",     { 12,  9}, {2, 2}, Building::Dir::s, God_id::Apollo);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_APOLLOW,     "STATUE_OF_APOLLOW",     { 12, 11}, {2, 2}, Building::Dir::w, God_id::Apollo);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ARESN,       "STATUE_OF_ARESN",       { 14,  5}, {2, 2}, Building::Dir::n, God_id::Ares);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ARESE,       "STATUE_OF_ARESE",       { 14,  7}, {2, 2}, Building::Dir::e, God_id::Ares);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ARESS,       "STATUE_OF_ARESS",       { 14,  9}, {2, 2}, Building::Dir::s, God_id::Ares);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ARESW,       "STATUE_OF_ARESW",       { 14, 11}, {2, 2}, Building::Dir::w, God_id::Ares);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HEPHAESTUSN, "STATUE_OF_HEPHAESTUSN", { 16,  5}, {2, 2}, Building::Dir::n, God_id::Hephaestus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HEPHAESTUSE, "STATUE_OF_HEPHAESTUSE", { 16,  7}, {2, 2}, Building::Dir::e, God_id::Hephaestus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HEPHAESTUSS, "STATUE_OF_HEPHAESTUSS", { 16,  9}, {2, 2}, Building::Dir::s, God_id::Hephaestus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HEPHAESTUSW, "STATUE_OF_HEPHAESTUSW", { 16, 11}, {2, 2}, Building::Dir::w, God_id::Hephaestus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_APHRODITEN,  "STATUE_OF_APHRODITEN",  { 18,  5}, {2, 2}, Building::Dir::n, God_id::Aphrodite);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_APHRODITEE,  "STATUE_OF_APHRODITEE",  { 18,  7}, {2, 2}, Building::Dir::e, God_id::Aphrodite);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_APHRODITES,  "STATUE_OF_APHRODITES",  { 18,  9}, {2, 2}, Building::Dir::s, God_id::Aphrodite);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_APHRODITEW,  "STATUE_OF_APHRODITEW",  { 18, 11}, {2, 2}, Building::Dir::w, God_id::Aphrodite);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HERMESN,     "STATUE_OF_HERMESN",     { 20,  5}, {2, 2}, Building::Dir::n, God_id::Hermes);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HERMESE,     "STATUE_OF_HERMESE",     { 20,  7}, {2, 2}, Building::Dir::e, God_id::Hermes);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HERMESS,     "STATUE_OF_HERMESS",     { 20,  9}, {2, 2}, Building::Dir::s, God_id::Hermes);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HERMESW,     "STATUE_OF_HERMESW",     { 20, 11}, {2, 2}, Building::Dir::w, God_id::Hermes);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_DIONYSUSN,   "STATUE_OF_DIONYSUSN",   { 22,  5}, {2, 2}, Building::Dir::n, God_id::Dionysus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_DIONYSUSE,   "STATUE_OF_DIONYSUSE",   { 22,  7}, {2, 2}, Building::Dir::e, God_id::Dionysus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_DIONYSUSS,   "STATUE_OF_DIONYSUSS",   { 22,  9}, {2, 2}, Building::Dir::s, God_id::Dionysus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_DIONYSUSW,   "STATUE_OF_DIONYSUSW",   { 22, 11}, {2, 2}, Building::Dir::w, God_id::Dionysus);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ATLASN,      "STATUE_OF_ATLASN",      { 24,  5}, {2, 2}, Building::Dir::n, God_id::Atlas);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ATLASE,      "STATUE_OF_ATLASE",      { 24,  7}, {2, 2}, Building::Dir::e, God_id::Atlas);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ATLASS,      "STATUE_OF_ATLASS",      { 24,  9}, {2, 2}, Building::Dir::s, God_id::Atlas);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_ATLASW,      "STATUE_OF_ATLASW",      { 24, 11}, {2, 2}, Building::Dir::w, God_id::Atlas);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HERAN,       "STATUE_OF_HERAN",       { 26,  5}, {2, 2}, Building::Dir::n, God_id::Hera);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HERAE,       "STATUE_OF_HERAE",       { 26,  7}, {2, 2}, Building::Dir::e, God_id::Hera);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HERAS,       "STATUE_OF_HERAS",       { 26,  9}, {2, 2}, Building::Dir::s, God_id::Hera);
				add_building_type(Building::Type::statue_large, Building_id::STATUE_OF_HERAW,       "STATUE_OF_HERAW",       { 26, 11}, {2, 2}, Building::Dir::w, God_id::Hera);
				}

			//Buildings
			if (true)
				{
				add_building_type(Building::Type::building,  Building_id::SANCTUARY_SMALL,            "SANCTUARY_SMALL",            {14, 1}, {4, 4});
				add_building_type(Building::Type::sanctuary, Building_id::SANCTUARY_FRONT,            "SANCTUARY_FRONT",            {14, 1}, {4, 4}, Building::Dir::s);
				add_building_type(Building::Type::sanctuary, Building_id::SANCTUARY_BACK,             "SANCTUARY_BACK",             {18, 1}, {4, 4}, Building::Dir::n);
				add_building_type(Building::Type::sanctuary, Building_id::SANCTUARY_FRONT_HORIZONTAL, "SANCTUARY_FRONT_HORIZONTAL", {22, 1}, {4, 4}, Building::Dir::e);
				add_building_type(Building::Type::sanctuary, Building_id::SANCTUARY_BACK_HORIZONTAL,  "SANCTUARY_BACK_HORIZONTAL",  {26, 1}, {4, 4}, Building::Dir::w);
				add_building_type(Building::Type::building,  Building_id::ALTAR,                      "ALTAR",                     {30, 1}, {2, 2});
				add_building_type(Building::Type::building,  Building_id::OBSERVATORY,                "OBSERVATORY",               {28, 5}, {4, 4});
				add_building_type(Building::Type::building,  Building_id::MUSEUM,                     "MUSEUM",                    {0, 13}, {6, 6});
				add_building_type(Building::Type::building,  Building_id::GRAND_POSEIDON_STATUE,      "GRAND_POSEIDON_STATUE",     {6, 13}, {6, 6});
				}

			//Other
			if (true)
				{ 
				add_building_type(Building::Type::other,        Building_id::SANC_FLAG_POLE, "SANC_FLAG_POLE", {18, 0}, {1, 1});
				add_building_type(Building::Type::experimental, Building_id::EXPERIMENTAL,   "?",              {19, 0}, {1, 1});
				}

			//Resources
			if (true)
				{
				add_building_type(Building::Type::resource, Building_id::SILVER_ORE,  "SILVER_ORE",  {14, 0}, {1, 1});
				add_building_type(Building::Type::resource, Building_id::COPPER_ORE,  "COPPER_ORE",  {15, 0}, {1, 1});
				add_building_type(Building::Type::resource, Building_id::OLIVE_TREES, "OLIVE_TREES", {16, 0}, {1, 1});
				add_building_type(Building::Type::resource, Building_id::GRAPE_VINES, "GRAPE_VINES", {17, 0}, {1, 1});
				}
			};

		void add_building_type(Building::Type type, Building_id id, const char* name, sf::Vector2u pos, sf::Vector2u size, Building::Dir dir = Building::Dir::n, God_id god = God_id::Zeus)
			{
			building_types.emplace(id, Building{type, id, name, pos, size, spritesheet, dir, god});
			}



		Building& rotate(Building& building)
			{
			if (building.type == Building::Type::statue_large || building.type == Building::Type::statue_small)
				{
				if (building.dir == Building::Dir::w) { return building_types[Building_id{building.id - 3}]; }
				else { return building_types[Building_id{building.id + 1}]; }
				}
			else if (building.type == Building::Type::tile)
				{
				//Get what index of tile you are regardless of the exact type
				int32_t delta_id = 0;
				if (building.god == God_id::none) { delta_id = building.id - Building_id::SANCTUARY_TILE0; }
				else { delta_id = building.id - Building_id::FIREPOT_TILE0; }

				int32_t target_id; //If was torchless, add the delta to the torch 0, if was with torch turn to torchless
				if (building.god == God_id::none) { target_id = Building_id::FIREPOT_TILE0 + delta_id; }
				else { target_id = Building_id::SANCTUARY_TILE0 + delta_id; }

				return building_types[Building_id{target_id}];
				}
			else if (building.type == Building::Type::sanctuary)
				{
				switch (building.id)
					{
					case Building_id::SANCTUARY_FRONT:            return building_types[Building_id::SANCTUARY_BACK_HORIZONTAL];
					case Building_id::SANCTUARY_BACK_HORIZONTAL:  return building_types[Building_id::SANCTUARY_BACK];
					case Building_id::SANCTUARY_BACK:             return building_types[Building_id::SANCTUARY_FRONT_HORIZONTAL];
					case Building_id::SANCTUARY_FRONT_HORIZONTAL: return building_types[Building_id::SANCTUARY_FRONT];
					}
				}
			else { return building; }
			}

		Building& variant(Building& building)
			{
			if (building.type == Building::Type::tile)
				{
				if (building.dir == Building::Dir::_5) { return building_types[Building_id{building.id - 5}]; }
				else { return building_types[Building_id{building.id + 1}]; }
				}
			else if(building.type == Building::Type::statue_large || building.type == Building::Type::statue_small)
				{
				//Get the delta for the id with the current direction relative to the id to north
				int32_t delta_nord_id = 0;
				switch (building.dir)
					{
					case Building::Dir::n: delta_nord_id = 0; break;
					case Building::Dir::e: delta_nord_id = 1; break;
					case Building::Dir::s: delta_nord_id = 2; break;
					case Building::Dir::w: delta_nord_id = 3; break;
					}
				
				if (building.type == Building::Type::statue_small)
					{
					switch (building.god)
						{
						case God_id::Zeus:		 return building_types[Building_id{Building_id::SCULPTURE_POSEIDON_N   + delta_nord_id}];
						case God_id::Poseidon:	 return building_types[Building_id{Building_id::SCULPTURE_HADES_N      + delta_nord_id}];
						case God_id::Hades:		 return building_types[Building_id{Building_id::SCULPTURE_DEMETER_N    + delta_nord_id}];
						case God_id::Demeter:	 return building_types[Building_id{Building_id::SCULPTURE_ATHENA_N     + delta_nord_id}];
						case God_id::Athena:	 return building_types[Building_id{Building_id::SCULPTURE_ARTEMIS_N    + delta_nord_id}];
						case God_id::Artemis:	 return building_types[Building_id{Building_id::SCULPTURE_APOLLO_N     + delta_nord_id}];
						case God_id::Apollo:	 return building_types[Building_id{Building_id::SCULPTURE_ARES_N       + delta_nord_id}];
						case God_id::Ares:		 return building_types[Building_id{Building_id::SCULPTURE_HEPHAESTUS_N + delta_nord_id}];
						case God_id::Hephaestus: return building_types[Building_id{Building_id::SCULPTURE_APHRODITE_N  + delta_nord_id}];
						case God_id::Aphrodite:	 return building_types[Building_id{Building_id::SCULPTURE_HERMES_N     + delta_nord_id}];
						case God_id::Hermes:	 return building_types[Building_id{Building_id::SCULPTURE_DIONYSUS_N   + delta_nord_id}];
						case God_id::Dionysus:	 return building_types[Building_id{Building_id::SCULPTURE_ATLAS_N      + delta_nord_id}];
						case God_id::Atlas:		 return building_types[Building_id{Building_id::SCULPTURE_HERA_N       + delta_nord_id}];
						case God_id::Hera:		 return building_types[Building_id{Building_id::SCULPTURE_ZEUS_N       + delta_nord_id}];
						}
					}
				else if(building.type == Building::Type::statue_large)
					{
					switch (building.god)
						{
						case God_id::Zeus:		 return building_types[Building_id{Building_id::STATUE_OF_POSEIDONN   + delta_nord_id}];
						case God_id::Poseidon:	 return building_types[Building_id{Building_id::STATUE_OF_HADESN      + delta_nord_id}];
						case God_id::Hades:		 return building_types[Building_id{Building_id::STATUE_OF_DEMETERN    + delta_nord_id}];
						case God_id::Demeter:	 return building_types[Building_id{Building_id::STATUE_OF_ATHENAN     + delta_nord_id}];
						case God_id::Athena:	 return building_types[Building_id{Building_id::STATUE_OF_ARTEMISN    + delta_nord_id}];
						case God_id::Artemis:	 return building_types[Building_id{Building_id::STATUE_OF_APOLLON     + delta_nord_id}];
						case God_id::Apollo:	 return building_types[Building_id{Building_id::STATUE_OF_ARESN       + delta_nord_id}];
						case God_id::Ares:		 return building_types[Building_id{Building_id::STATUE_OF_HEPHAESTUSN + delta_nord_id}];
						case God_id::Hephaestus: return building_types[Building_id{Building_id::STATUE_OF_APHRODITEN  + delta_nord_id}];
						case God_id::Aphrodite:	 return building_types[Building_id{Building_id::STATUE_OF_HERMESN     + delta_nord_id}];
						case God_id::Hermes:	 return building_types[Building_id{Building_id::STATUE_OF_DIONYSUSN   + delta_nord_id}];
						case God_id::Dionysus:	 return building_types[Building_id{Building_id::STATUE_OF_ATLASN      + delta_nord_id}];
						case God_id::Atlas:		 return building_types[Building_id{Building_id::STATUE_OF_HERAN       + delta_nord_id}];
						case God_id::Hera:		 return building_types[Building_id{Building_id::STATUE_OF_ZEUSN       + delta_nord_id}];
						}
					}
				}
			else { return building; }
			}

		Building* rotate(Building* ptr)  { return &rotate (*ptr); }
		Building* variant(Building* ptr) { return &variant(*ptr); }

	private:
	};
