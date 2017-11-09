#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

bool in_bounds(const int &low, const int &high, const int &in)
{
	return (in >= low && in <= high);
}

int main(void)
{
	auto lowval = 0, highval = 0, num = 0;

	const std::string message = "Inputted value was ";

	std::cout << "Please input a number that works as lower limit" << std::endl;
	std::cin >> lowval;

	std::cout << "Please input a number that works as upper limit" << std::endl;
	std::cin >> highval;

	std::cout << "Please enter a value thats less than " << lowval << " or more than " << highval << std::endl;
	std::cin >> num;

	if (in_bounds(lowval, highval, num))
		std::cout << message.data() << num << " - it's not less than " << lowval << " or more than " << highval << std::endl;
	else {
		std::cout << message.data() << num;
		if (num < lowval)
			std::cout << " - it's less than " << lowval << std::endl;
		else if (num > highval)
			std::cout << " - it's more than " << highval << std::endl;
	}
	
	return EXIT_SUCCESS;
}