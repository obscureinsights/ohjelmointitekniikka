#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

bool in_bounds( const int &low, const int &high, const int &in )
{
	return (in > low && in < high);
}

int main(void)
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

	std::cout << "Please input a value between " << low_value << " and " << hi_value << std::endl;
	std::cin >> num;

	while (!in_bounds(low_value, hi_value, num)) {
		std::cout << "Value is not between " << low_value << " and " << hi_value << std::endl;
		std::cout << "Please type another number" << std::endl;
		std::cin >> num;
	}

	std::cout << "You typed " << num << std::endl;
	
	return EXIT_SUCCESS;
}