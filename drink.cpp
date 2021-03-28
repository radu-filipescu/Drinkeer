#include "drink.h"

drink::drink() {
	name = type = "";
	alch_percent = price = 0;
}
drink::drink(std::string s) {
	name = s;
	type = "";
	alch_percent = price = 0;
}

bool drink::operator==(const drink& A) {
	return name == A.name && alch_percent == A.alch_percent;
}
void drink::set_name(string A) {
	name = A;
}
string drink::get_name() {
	return name;
}
void drink::set_type(string A) {
	type = A;
}
string drink::get_type() {
	return type;
}