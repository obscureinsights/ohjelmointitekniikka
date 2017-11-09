#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdint.h>
#include <string>
#include <sstream>

constexpr uint8_t min_val = 1;
constexpr uint8_t max_val = 3;

bool is_equal( const int &in )
{
	const auto rand_num = min_val + ::rand() % ( max_val - min_val + 1 );

	return in == rand_num;
}

bool in_bounds( const int &low, const int &high, const int &in )
{
	return (in >= low && in <= high);
}

std::string minmax_message( void )
{
	std::stringstream ss;
	ss << "[" << static_cast<int>( min_val ) << "-" << static_cast<int>( max_val ) << "]";
	return ss.str();
}

int main(void)
{
	int cur_score = 0, max_guesses = 20, num_in = 0;
	
	::srand( std::time(nullptr) );
	
	uint8_t i = 0;

	while( i < max_guesses )
	{		
		std::cout << "Guess number between" << minmax_message() << ":";
		
		if (!(std::cin >> num_in) ) {
			std::cin.clear();
			std::cin.ignore( std::numeric_limits< std::streamsize>::max(), '\n');
			continue;
		}

		if( !in_bounds( min_val, max_val, num_in ) )
		{
			std::cout << "Value " << num_in << " is not between " << minmax_message() << std::endl;
			num_in = 0;
			continue;
		}
		else 
		{
			if (is_equal(num_in))
			{
				cur_score++;
				std::cout << "Correct! Result: " << cur_score << "/" << static_cast<int>(i+1) << std::endl;
			}
			else
			{
				std::cout << "Wrong. Result: " << cur_score << "/" << static_cast<int>(i+1) << std::endl;
			}
		}
		i++;
	}
	return EXIT_SUCCESS;
}