#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdint.h>
#include <string>
#include <sstream>

constexpr int min_max[4] = { 0, 9, 10, 99 };

using retval_t = enum {
	k_Negative = -2,
	k_MinusOne = -1,
	k_NotNumbr = 0,
	k_ValidInp = 1
};

std::string print_result( const int &in )
{
	std::stringstream ss;
	ss << "Number " << in;

	if (in >= min_max[0] && in <= min_max[1]) // 0..9
		ss << " in range [" << min_max[0] << "," << min_max[1] << "]";
	else if (in >= min_max[2] && in < min_max[3]) // 10..99
		ss << " in range [" << min_max[2] << "," << min_max[3] << "]";
	else if (in > min_max[3]) // >= 100
		ss << " is larger or equal to 100";

	return ss.str();
}

bool is_positive( const int &in ) {
	return in >= 0;
}

retval_t is_valid( const int &in )
{
	if (in == -1)
		return retval_t::k_MinusOne;
	if (!is_positive(in))
		return retval_t::k_Negative;

	return k_ValidInp;
}

retval_t request_input( int &in )
{
	std::cout << "Input a positive integer (>=0)" << std::endl;
	std::cin >> in;

	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		return k_NotNumbr;
	}

	return is_valid(in);
}

int main( void )
{
	static int num_in = 0;
	static auto cur_state = request_input(num_in);

	while ( cur_state == k_Negative || cur_state == k_NotNumbr )
		cur_state = request_input(num_in);

	std::cout << print_result(num_in) << std::endl;
	
	return EXIT_SUCCESS;
}