#pragma once
#include <string>
#include <vector>
#include "user.h"

class place
{
private:
	std::string name;
	std::string location;
	std::vector <std::string> list_of_drinks;
public:
	std::vector <user*> usual_users;
	std::vector <user*> banned_users;

	place();
	place(const place& p);
	std::string get_name();
	void set_name(std::string name);
	std::string get_location();
	void set_location(std::string loc_name);
	void add_drink_served(std::string name);
	bool check_if_serves(std::string name);
	bool check_if_banned(user* p);
	void ban_user(user* p);
	void add_usual_user(user* p);
	virtual std::string generate_invite() {
		return "You've been invited to " + name + ", at " + location + ".\n";
	}
};

