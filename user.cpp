#include "user.h"

user::user() {
	firstname = lastname = "";
	age = 18;
	facebook_link = instagram_link = "";
}
user::user(const user& A) {
	firstname = A.firstname;
	lastname = A.lastname;
	age = A.age;
	friends = A.friends;
	fav_drinks = A.fav_drinks;
	facebook_link = A.facebook_link;
	instagram_link = A.instagram_link;
}
user::user(string fname, string lname) {
	firstname = fname;
	lastname = lname;
	age = 18;
	facebook_link = instagram_link = "";
}
void user::set_name(string fname, string lname) {
	firstname = fname;
	lastname = lname;
}
string user::get_name() {
	return firstname + " " + lastname;
}
void user::set_age(int _age) {
	age = _age;
}
int user::get_age() {
	return age;
}
void user::set_fb(string _link) {
	facebook_link = _link;
}
string user::get_fb() {
	return facebook_link;
}
void user::set_insta(string _link) {
	instagram_link = _link;
}
string user::get_insta() {
	return instagram_link;
}
void user::add_friend(user A) {
	string _name = A.get_name();
	if (friends.find(_name) == friends.end())
		friends[_name] = A;
}
bool user::check_if_friend(user A) {
	string _name = A.get_name();
	return (friends.find(_name) != friends.end());
}
void user::add_fav_drink(drink A) {
	string _name = A.get_name();
	if (fav_drinks.find(_name) == fav_drinks.end())
		fav_drinks[_name] = A;
}
void user::new_notification(notification A) {
	inbox.push_back(A);
}
void user::print_notifications() {
	for (int i = 0; i < (int)inbox.size(); ++i) {
		inbox[i].print_notification();
		cout << '\n';
	}
}
void user::send_notification(user& A, std::string _date, std::string _time ) {
	A.new_notification(notification(_date, _time));
}