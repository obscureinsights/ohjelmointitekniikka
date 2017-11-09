#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdint.h>
#include <string>

std::string print_range( const int &num )
{
	const auto num_digits = std::to_string(num).length();

	std::string range = "0,0";

	if (num_digits == 1)
		range = "0,9";
	else if (num_digits == 2)
		range = "10,99";
	else if (num_digits >= 3)
		range = "100," + std::to_string(std::numeric_limits<int>::max());

	return std::string("belongs to range [" + range + "]");
}

int main( void )
{
	int user_num = 0;

	while (user_num >= 0)
	{
		std::cout << "Please input a positive decimal value (>=0)" << std::endl;

		if (!(std::cin >> user_num) || std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (user_num < 0)
			break;

		std::cout << "Number" << std::setw(std::to_string(user_num).length() + 1) << user_num << std::setw(print_range(user_num).length() + 1) << print_range(user_num) << std::endl;
	}

	return EXIT_SUCCESS;
}