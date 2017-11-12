#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

int main( void )
{
	std::string usr_inp1, usr_inp2;

	while( usr_inp1.empty() ) {
		std::cout << "Write first sentence:" << std::endl;
		std::getline( std::cin, usr_inp1 );
	}

	while (usr_inp2.empty()) {
		std::cout << "Write second sentence:" << std::endl;
		std::getline( std::cin, usr_inp2 );
	}

	for( char &c : usr_inp1 )
	{
		const int index = &c - &usr_inp1.at(0);

		if ( index <= usr_inp2.length() )
		{
			if ( usr_inp2.at(index) == c )
			{
				if ( ::isdigit(c) )
					usr_inp1.at(index) = '?';
				else
					usr_inp2.at(index) = '"';
			}
		}
	}

	std::cout << "First sentence: " << usr_inp1 << std::endl;
	std::cout << "Second sentence: " << usr_inp2 << std::endl;
	
	return EXIT_SUCCESS;
}