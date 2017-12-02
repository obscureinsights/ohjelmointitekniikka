#include <algorithm>
#include <clocale>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>

constexpr uint8_t num_cols = 9;
constexpr uint8_t num_rows = 10;

std::deque<int> random_array( int len )
{
	std::deque<int> out(len);

	for( auto &i : out )
		i = rand() % len+1;

	return out;
}

int main( void )
{
	::srand( std::time(nullptr) );
	
	while ( true )
	{
		system("cls");

		auto num_array = random_array(num_cols);

		std::cout << std::endl;

		/* Uncomment to print the random numbers used for diagram
		for (const auto &i : num_array)
		std::cout << std::setw(3) << std::setfill(' ') << i;*/
		
		for (auto cur_row = num_rows; cur_row > 0; cur_row--)
		{
			for (auto cur_col = 0; cur_col < num_cols; cur_col++)
			{
				if (cur_row <= num_array[cur_col])
					std::cout << std::setw(3) << '*' << std::setfill(' ');
				else
					std::cout << std::setw(3) << "" << std::setfill(' ');
			}
			std::cout << std::endl;
		}

		for (auto i = 1; i <= 9; i++)
			std::cout << std::setw(3) << std::setfill(' ') << i;

		std::string user_inp;
		
		while ( user_inp.empty() )
		{
			std::cout << std::endl << std::endl;
			std::cout << "Again? Enter Y/y, otherwise exit program" << std::endl;
			std::getline( std::cin, user_inp );
		}

		if (user_inp == "Y" || user_inp == "y")
			continue;
		else
			break;
	}

	return EXIT_SUCCESS;
}