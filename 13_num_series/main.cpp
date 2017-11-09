#include <deque>
#include <iostream>
#include <numeric>

int main(void)
{
	std::deque<unsigned int> nums_list;

	static int i = 0;
	while (i <= 22)
	{
		if (i < 3)
		{
			std::cout << i << std::endl;
			nums_list.emplace_back(i++);
		}
		else
		{
			unsigned int sum = std::accumulate(nums_list.begin(), nums_list.end(), 0);

			nums_list.pop_front();
			nums_list.emplace_back(sum);

			std::cout << sum << std::endl;

			i++;
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}