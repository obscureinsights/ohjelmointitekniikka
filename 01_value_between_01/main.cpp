#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

int main( void )
{
	auto num = 0;

	std::string message = "Inputted value was ";

	std::cout << "Please input a number that is smaller than 1 or larger than 10" << std::endl;
	std::cin >> num;

	std::stringstream str_buffer;

	str_buffer << message << num << " ";

	if (num <= 0)
		std::cout << str_buffer.str() << "which is smaller than 1" << std::endl;
	else if (num > 10)
		std::cout << str_buffer.str() << "which is larger than 10" << std::endl;
	else 
		std::cout << str_buffer.str() << "which is not smaller than 1 or larger than 10" << std::endl;

	return EXIT_SUCCESS;
}