#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>
#include <sstream>

int main( void )
{
	while ( true )
	{
		std::string input, temp;

		std::cout << "Please write a line of words" << std::endl;
		std::getline( std::cin, input );
		auto num_count = 0;

		if( input.empty() )
			continue;

		std::stringstream ss( input );

		while ( std::getline(ss, temp, ' ') )
		{
			if( std::all_of( temp.begin(), temp.end(), ::isdigit ) )
			{
				std::cout << std::endl;
				std::cout << temp << std::endl;
				num_count++;
			}
			else
			{
				std::cout << temp << ' ';
			}
		}

		if( num_count == 0 )
			break;
	}
	return EXIT_SUCCESS;
}