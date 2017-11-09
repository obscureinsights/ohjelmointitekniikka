#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

int main( void )
{
	auto highval = 0, num = 0;

	const std::string message = "Inputted value was ";

	std::cout << "Please input a number that works as upper limit" << std::endl;
	
	std::cin >> highval;

	std::cout << "Please input a number between 1 and " << highval << std::endl;

	std::cin >> num;

	std::stringstream str_buffer;

	str_buffer << message << num << " ";

	if (num < 1 || num > highval)
		std::cout << str_buffer.str() << " which is not between 1-" << highval << std::endl;
	else
		std::cout << str_buffer.str();
	
	return EXIT_SUCCESS;
}