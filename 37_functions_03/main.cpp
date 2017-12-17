#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

void print_array( const std::deque<int> &array )
{
	for( const auto &i : array )
		std::cout << i << std::endl;
}
 
int resolve_more_than10( const std::deque<int> &array )
{
	int count = 0;

	for (const auto &i : array)
	{
		if( i > 10 )
			count++;
	}

	return count;
}

std::deque<int> read_nums( void )
{
	std::deque<int> ret_val;

	while( ret_val.size() != 10 )
	{
		int user_inp = 0;
		std::cout << "Type a positive number: ";
		
		if (!(std::cin >> user_inp) || std::cin.fail() || user_inp < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		ret_val.push_back(user_inp);
	}

	return ret_val;
}

int main(void)
{
	auto num_arr = read_nums();

	if( num_arr.size() == 10 )
	{
		print_array( num_arr );
		std::cout << "Array contains " << resolve_more_than10( num_arr ) << " numbers that are > 10" << std::endl;
	}

	system("pause");

	return EXIT_SUCCESS;
}