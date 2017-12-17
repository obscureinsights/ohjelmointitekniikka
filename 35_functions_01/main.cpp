#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

void print_line( const int &multiplier, const int &multiplicand )
{
	std::cout << multiplier << "*" << multiplicand << "=" << multiplier*multiplicand << std::endl;
}

void print_table( const int &min_multiplier, const int &min_multiplicand, const int &max_multiplier, const int &max_multiplicand )
{
	for( auto i = min_multiplier; i <= max_multiplier; i++ )
	{
		for( auto k = min_multiplicand; k <= max_multiplicand; k++ )
		{
			print_line(i, k);
		}
	}
}

void read_limits( int &min_multiplier, int &min_multiplicand, int &max_multiplier, int &max_multiplicand )
{
	while (min_multiplier == 0 || min_multiplicand == 0 || max_multiplier == 0 || max_multiplicand == 0 )
	{
		std::cout << "Enter minimum multiplier: ";
		if (!(std::cin >> min_multiplier) || std::cin.fail() || min_multiplier <= 0 )
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		std::cout << "Enter minimum multiplicand: ";
		if (!(std::cin >> min_multiplicand) || std::cin.fail() || min_multiplicand <= 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		std::cout << "Enter maximum multiplier: ";
		if (!(std::cin >> max_multiplier) || std::cin.fail() || max_multiplier <= 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		std::cout << "Enter maximum multiplicand: ";
		if (!(std::cin >> max_multiplicand) || std::cin.fail() || max_multiplicand <= 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
}

int main(void)
{
	int a = 0, b = 0, c = 0, d = 0;

	read_limits(a, b, c, d);
	print_table(a, b, c, d);
	system("pause");

	return EXIT_SUCCESS;
}