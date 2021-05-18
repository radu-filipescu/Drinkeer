#pragma once
#include "place.h"
#include "drink.h"

class place_factory
{
public:
	static place Hipster_bar(string name) {
		place X;
		X.set_name(name);
		X.add_drink_served("Ginger beer");
		X.add_drink_served("Root beer");
		X.add_drink_served("Chateau Lafitte 1787");
		X.set_location("Centrul vechi");

		return X;
	}
	static place Jazz_lounge(string name) {
		place X;

		X.add_drink_served("Martini");
		X.add_drink_served("Classic Coca-Cola");

		return X;
	}

	static place Dana_Marijuana(string name) {
		place X;

		X.add_drink_served("Bere");
		X.add_drink_served("Visinata");
		X.set_location("Unirii");

		return X;
	}
};

