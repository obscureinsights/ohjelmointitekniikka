#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

using unit_t = enum
{
	k_Hours = 0,
	k_Mins = 1,
	k_Secs = 2
};

std::string get_request_message(const unit_t &type)
{
	std::string message = "Please input ";

	switch (type)
	{
	case unit_t::k_Hours:
		message.append("hours (0-23)");
		break;
	case unit_t::k_Mins:
		message.append("minutes (0-59)");
		break;
	case unit_t::k_Secs:
		message.append("seconds (0-59)");
		break;
	default:
		message = "Invalid format passed";
		break;
	}
	return message;
}

int request_time_unit(const unit_t &type)
{
	int ret_val = 0;

	std::cout << get_request_message(type) << std::endl;

	if (!(std::cin >> ret_val) || std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return -1;
	}

	return ret_val;
}

std::string get_fixed_value(const int &value)
{
	return std::to_string(value).length() == 1 ? "0" + std::to_string(value) : std::to_string(value);
}

std::string to_fixed_time(const int &hours, const int &minutes, const int &seconds)
{
	std::string ret_val = "The time you input was: ";

	ret_val.append(get_fixed_value(hours) + ":");
	ret_val.append(get_fixed_value(minutes) + ":");
	ret_val.append(get_fixed_value(seconds));

	return ret_val;
}

int main(void)
{
	auto h = 0, m = 0, s = 0;
	std::string time = "xx:xx:xx";

	while (true)
	{
		auto n = time.find("00:00:00");

		if (n != std::string::npos)
			break;

		h = request_time_unit(unit_t::k_Hours);

		if (h < 0 || h > 23)
			continue;

		m = request_time_unit(unit_t::k_Mins);

		if (m < 0 || m > 59)
			continue;

		s = request_time_unit(unit_t::k_Secs);

		if (s < 0 || s > 59)
			continue;

		time = to_fixed_time(h, m, s);
		std::cout << time << std::endl;
	}
	return EXIT_SUCCESS;
}