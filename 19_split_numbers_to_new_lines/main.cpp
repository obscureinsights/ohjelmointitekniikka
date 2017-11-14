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
		std::getline( std::cin, input );

		if( input.empty() )
			continue;

		std::stringstream ss( input );

		while ( std::getline(ss, temp, ' ') )
		{
			if( std::all_of( temp.begin(), temp.end(), ::isdigit ) )
			{
				std::cout << std::endl;
				std::cout << temp << std::endl;
			}
			else
			{
				std::cout << temp << ' ';
			}
		}
	}
	return EXIT_SUCCESS;
}