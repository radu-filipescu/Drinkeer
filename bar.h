#pragma once
#include "place.h"
#include <vector>
#include <string>

class bar : public place
{
	std::vector <std::string> bar_games;
	bool has_offers;
public:
	void add_bar_game(std::string game);
	std::vector <std::string> list_of_games();
	std::string generate_invite();
};

