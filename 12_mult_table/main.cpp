#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void draw_table(const int &low, const int &high, const std::vector<int> &table)
{
	static int line = 0;

	std::cout << "    ";
	for (auto i = low; i <= high; i++)
		std::cout << std::setw(4) << i;

	std::cout << std::setw(4) << std::endl;

	for (const auto &p : table)
	{
		if (line == low + 1) {
			std::cout << std::endl;
			line = 0;
		}
		std::cout << p << std::setw(4);
		line++;
	}
}


std::vector<int>
make_table(const int &low, const int &high)
{
	std::vector<int> mult_table;
	static int prev_i = low;

	for (auto i = low; i <= high; ++i)
	{
		mult_table.push_back(i);

		for (auto x = low; x <= high; ++x) {
			mult_table.push_back(static_cast<int>(i*x));
		}
	}
	return mult_table;
}

int main(void)
{
	const int low = 7;
	const int high = 13;

	std::vector<int> multiplier_table = make_table(low, high);

	if (multiplier_table.size() > 0)
		draw_table(low, high, multiplier_table);

	return EXIT_SUCCESS;
}