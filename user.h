#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "drink.h"
#include "notification.h"

using namespace std;

class user
{
	string firstname, lastname;
	int age = 18;
	unordered_map <string, user*> friends;
	unordered_map <string, drink> fav_drinks;
	string facebook_link;
	string instagram_link;
	vector <notification> inbox;

public:
	user();
	user(const user& A);
	user(string fname, string lname);
	~user() {}
	void operator = (const user& A) {
		firstname = A.firstname;
		lastname = A.lastname;
		age = A.age;
		friends = A.friends;
		fav_drinks = A.fav_drinks;
		facebook_link = A.facebook_link;
		instagram_link = A.instagram_link;
	}
	bool operator == (const user& A) {
		return firstname == A.firstname && lastname == A.lastname &&
			age == A.age;
	}
	void set_name(string fname, string lname);
	string get_name();
	void set_age(int _age);
	int get_age();
	void set_fb(string _link);
	string get_fb();
	void set_insta(string _link);
	string get_insta();
	void add_friend(user& A);
	bool check_if_friend(user& A);
	bool check_if_drink(std::string s);
	vector <drink> get_fav_drinks();
	void add_fav_drink(drink A);
	void new_notification(notification A);
	void print_notifications();
	void send_notification(user& A, std::string _date, std::string _time );
};

