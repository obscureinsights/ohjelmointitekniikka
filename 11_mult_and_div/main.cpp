#include <cstdint>
#include <iostream>
#include <locale>
#include <string>

using choice_t = enum {
	k_Div = 0,
	k_Mult = 1,
	k_Quit = 2,
	k_Invalid = 3
};

choice_t input_to_type(std::string &input)
{
	std::string out;
	std::getline(std::cin, input);

	if (input.find("*") != std::string::npos)
		return choice_t::k_Mult;
	else if (input.find("\\") != std::string::npos)
		return choice_t::k_Div;
	else if (input.find("l") != std::string::npos || input.find("L") != std::string::npos)
		return choice_t::k_Quit;

	return choice_t::k_Invalid;
}

double do_calc(const choice_t &type, const double &num1, const double &num2)
{
	double ret_val = 0;

	if (type == choice_t::k_Mult) {
		std::cout << num1 << " * " << num2 << " = ";
		return static_cast<double>(num1*num2);
	}
	else if (type == choice_t::k_Div)
	{
		if (num2 == 0) {
			std::cout << "Cannot perform division by 0" << std::endl;
			return 0;
		}
		std::cout << num1 << " / " << num2 << " = ";
		return static_cast<double>(num1 / num2);
	}

	return 0;
}

bool in_bounds(const double &min, const double &max, const double &value) {
	return value >= min && value <= max;
}

int main(void)
{
	const std::string message[] =
	{
		"*\t ... Multiply\n",
		"\\\t ... Divide\n",
		"L\\l \t ... Quit\n\n"
	};

	while (true)
	{
		double num_in[2] = { -1.0, -1.0 };

		std::cout << "Please write a value between [0,5]: ";

		if (!(std::cin >> num_in[0]) || std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (!in_bounds(0, 5, num_in[0])) {
			std::cout << "Value not between [0,5]\n" << "Please give both values again" << std::endl;
			continue;
		}

		std::cout << "Please write a second value between [0,5]: ";

		if (!(std::cin >> num_in[1]) || std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (!in_bounds(0, 5, num_in[1])) {
			std::cout << "Value not between [0,5]\n" << "Please give both values again" << std::endl;
			continue;
		}

		std::string input;
		choice_t type = input_to_type(input);

		for (const std::string &p : message)
			std::cout << p.data();

		while (type == choice_t::k_Invalid) {
			type = input_to_type(input);
		}

		std::cout << "You chose: " << input << std::endl;

		if (type == choice_t::k_Quit)
			break;

		std::cout << do_calc(type, num_in[0], num_in[1]) << std::endl;
	}
	return EXIT_SUCCESS;
}