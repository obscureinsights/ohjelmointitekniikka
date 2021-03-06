#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

bool find_num_from_array( const int &num, const std::deque<int> &array )
{
	auto retval = false;

	for( auto &i : array )
	{
		if (i == num) {
			retval = true;
			break;
		}
	}

	return retval;
}

std::deque<int> read_nums(void)
{
	std::deque<int> ret_val;

	while (ret_val.size() != 10)
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

void print_array( const std::deque<int> &array )
{
	for (const auto &i : array)
		std::cout << i << std::endl;
}

int main(void)
{
	auto num_arr = read_nums();

	if ( num_arr.size() == 10 )
	{
		print_array( num_arr );

		auto find_num = -1;

		while( find_num < 0 )
		{
			std::cout << "Please input a number to find from array: " << std::endl;
			if (!(std::cin >> find_num) || std::cin.fail())
			{
				std::cout << "Invalid input, please enter a number:" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		
		if( find_num_from_array( find_num, num_arr ) == true )
			std::cout << find_num << " found!" << std::endl;
		else
			std::cout << find_num << " not found!" << std::endl;

	}

	system("pause");

	return EXIT_SUCCESS;
}