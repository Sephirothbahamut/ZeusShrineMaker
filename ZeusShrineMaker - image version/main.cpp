#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

#include "Output.h"


God_id get_god(std::string s)
	{
	std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return std::tolower(c); });

	if (s.find("aphrodite")  != std::string::npos) { return God_id::Aphrodite; }
	if (s.find("apollo")     != std::string::npos) { return God_id::Apollo; }
	if (s.find("ares")       != std::string::npos) { return God_id::Ares; }
	if (s.find("artemis")    != std::string::npos) { return God_id::Artemis; }
	if (s.find("athena")     != std::string::npos) { return God_id::Athena; }
	if (s.find("atlas")      != std::string::npos) { return God_id::Atlas; }
	if (s.find("demeter")    != std::string::npos) { return God_id::Demeter; }
	if (s.find("dionysus")   != std::string::npos) { return God_id::Dionysus; }
	if (s.find("hades")      != std::string::npos) { return God_id::Hades; }
	if (s.find("hephaestus") != std::string::npos) { return God_id::Hephaestus; }
	if (s.find("hera")       != std::string::npos) { return God_id::Hera; }
	if (s.find("hermes")     != std::string::npos) { return God_id::Hermes; }
	if (s.find("poseidon")   != std::string::npos) { return God_id::Poseidon; }
	if (s.find("zeus")       != std::string::npos) { return God_id::Zeus; }

	return God_id::Zeus;
	}


int main(int argc, char** argv)
	{
	try
		{

	#ifdef NDEBUG
		if (argc != 2) { return 0; }
		const char* fname = argv[1];
	#else
		const char* fname = "Sanctuary_ARTEMIS.png";
	#endif
		std::string output_fname{fname};
		output_fname.erase(output_fname.begin() + output_fname.find_last_of('.'), output_fname.end());
		output_fname += ".txt";

		God_id god = get_god(output_fname);

		sf::Image image;
		if (!image.loadFromFile(fname)) { return 0; }
	
		std::cout << "Elaborating image of size: " << image.getSize().x << ", " << image.getSize().y << std::endl;

		std::string string = to_string(image, god);

		std::ofstream file(output_fname);
		file << string;
		}
	catch (std::runtime_error& e) { std::cout << e.what() << std::endl; }

	return 0;
	}