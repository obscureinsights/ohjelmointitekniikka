#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

bool in_bounds( const int &low, const int &high, const int &in )
{
	return (in >= low && in <= high);
}

int main( void )
{
	auto low_value = 0, hi_value = 0, num = 0;

	std::cout << "Please input a lower bound value" << std::endl;
	std::cin >> low_value;

	std::cout << "Please input a upper bound value" << std::endl;
	std::cin >> hi_value;

	if (low_value > hi_value)
	{
		auto backup_num = low_value;

		low_value = hi_value;
		hi_value = backup_num;
	}

	std::cout << "Please input a value that's smaller than " << low_value << " or bigger than " << hi_value << std::endl;
	std::cin >> num;

	if (in_bounds(low_value, hi_value, num))
		std::cout << "Value " << num << " is not smaller than " << low_value << " or bigger than " << hi_value << std::endl;
	else {
		if (num < low_value)
			std::cout << "You wrote: " << num << " - it's less than " << low_value << std::endl;
		else if (num > hi_value)
			std::cout << "You wrote: " << num << " - it's more than " << hi_value << std::endl;
	}
	
	return EXIT_SUCCESS;
}