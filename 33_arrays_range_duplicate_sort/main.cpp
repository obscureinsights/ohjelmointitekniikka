#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <string>

bool is_duplicate(const int &in, const std::deque<int> &arr)
{
	for (const auto &i : arr)
	{
		if (i == in)
			return true;
	}
	return false;
}

int main(void)
{
	std::deque<int> num_arr(10);
	num_arr.clear();

	while (num_arr.size() < 10)
	{
		int num_in = 0;

		while (num_in < 11 || num_in > 20)
		{
			std::cout << "Type a value between 11-20" << std::endl;

			if (!(std::cin >> num_in) || std::cin.fail())
				continue;
		}

		if (is_duplicate(num_in, num_arr))
			break;

		num_arr.push_back(num_in);
	}

	std::sort(num_arr.begin(), num_arr.end(), std::greater<int>());

	for (const auto &i : num_arr)
		std::cout << i << std::endl;

	return EXIT_SUCCESS;
}

