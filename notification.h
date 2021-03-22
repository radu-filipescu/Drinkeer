#pragma once
#include <string>
#include <iostream>

class notification
{
	static const std::string message;
	std::string date;
	std::string time;
	//place A;

public:
	notification(std::string _date, std::string _time);
	std::string print_notification();
};

