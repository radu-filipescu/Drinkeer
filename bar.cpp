#include "bar.h"

void bar::add_bar_game(std::string game) {
	bar_games.push_back(game);
}

std::vector<std::string> bar::list_of_games() {
	return bar_games;
}

std::string bar::generate_invite() {
	std::string str = "You've been invited to " + get_name() + ", on " + get_location() + " street.\n";
	
	if (bar_games.size() > 0) {
		str += "And play ";
		for (int i = 0; i < (int)bar_games.size(); ++i)
			str += bar_games[i] + ", ";

		str.pop_back();
		str.pop_back();
	}
	return str;
}