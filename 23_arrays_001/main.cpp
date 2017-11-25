#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>

int main( void )
{
	static int num_array[10];

	for( auto i = 0; i < 10; ++i ) 
	{
		auto user_num = 0;

		std::cout << "Please input a number: " << std::endl;
		while (!(std::cin >> user_num) || std::cin.fail())
		{
			std::cout << "Invalid input, please enter a number:" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		num_array[i] = user_num;
	}

	static auto cnt = 0;
	for (auto &i : num_array) {
		if( i > 10 )
			cnt++;
	}

	std::cout << "Array contains " << cnt << " values that are larger than 10" << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}