#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
#include <vector>

int main(void)
{
	std::deque<int> int_array = { 32, 12, 4, 6, 128, 77, 3, 1, 99, 22 };

	static int num = -1, index = -1;

	while (num < 0 || index < 0)
	{
		std::cout << "Please input number to place in array: ";
		while (!(std::cin >> num) || std::cin.fail())
		{
			std::cout << std::endl;
			std::cout << "Invalid input, please enter a number:" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cout << "Please input index to replace in array from 0 ... 9: ";
		while (!(std::cin >> index) || std::cin.fail() || index < 0 || index > 10)
		{
			std::cout << std::endl;
			std::cout << "Invalid input, please enter a number between 0 ... 9 :" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	int_array.insert(int_array.begin() + index, num);
	int_array.resize(10);

	for (const auto &i : int_array)
	{
		std::cout << i << std::endl;
	}

	system("pause");

	return EXIT_SUCCESS;
}