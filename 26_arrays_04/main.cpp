#include <algorithm>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>

int main( void )
{
	std::deque<int> num_array = { 45, 5, 10, 3, 90, 4, 11, 58, 4, 98 };

	auto find_num = 0;

	std::cout << "Please input a number to find from array: " << std::endl;
	while (!(std::cin >> find_num) || std::cin.fail())
	{
		std::cout << "Invalid input, please enter a number:" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	for ( auto i = 0; i < 10; ++i )
	{
		if( num_array.at(i) == find_num )
		{
			num_array.erase( num_array.begin() + i );
			num_array.emplace_back(0);
			break;
		}
	}

	std::cout << std::endl;

	for( auto &n : num_array )
		std::cout << n << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}