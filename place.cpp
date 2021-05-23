#include "place.h"

place::place() {
	name = location = "";
}

place::place(const place& p) {
	name = p.name;
	location = p.location;
	list_of_drinks = p.list_of_drinks;
	usual_users = p.usual_users;
	banned_users = p.banned_users;
}

std::string place::get_name() {
	return name;
}

void place::set_name(std::string placename) {
	name = placename;
}

std::string place::get_location() {
	return location;
}

void place::set_location(std::string loc_name) {
	location = loc_name;
}

void place::add_drink_served(std::string name) {
	list_of_drinks.push_back(name);
}

bool place::check_if_serves(std::string name) {
	for (int i = 0; i < (int)list_of_drinks.size(); ++i)
		if (list_of_drinks[i] == name)
			return true;
	return false;
}

bool place::check_if_banned(user* p) {
	for (int i = 0; i < (int)banned_users.size(); ++i)
		if ( *banned_users[i] == *p )
			return true;
	return false;
}

void place::ban_user(user* p) {
	banned_users.push_back(p);
}

void place::add_usual_user(user* p) {
	usual_users.push_back(p);
}

std::vector <user*> place::get_usual_users() {
	return usual_users;
}