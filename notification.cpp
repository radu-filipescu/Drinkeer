#include "notification.h"

const std::string notification::MESSAGE_HEADER = "You have been invited at a party on ";

notification::notification(std::string _date, std::string _time) {
	date = _date;
	time = _time;
}

std::string notification::print_notification() {
	return notification::MESSAGE_HEADER + " " + date + " " + time;
}