#pragma once
#include <string>

using namespace std;

class drink
{	
	string name;
	string type;
	double alch_percent;
	double price;        // in local currency, of course

public:
	drink();
	drink(std::string _name);
	bool operator==(const drink& A);
	void set_name( string A );
	string get_name();
	void set_type(string A);
	string get_type();
};

