#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

constexpr int num_cols = 5;
constexpr int num_rows = 5;

static void calc_vert(const std::deque<int> &table)
{
	int col_sums[5] = { 0 };
	int count = 0;

	for (int i = 0; i < table.size(); i++)
	{
		if (count == 5)
			count = 0;

		col_sums[count] += table.at(i);

		count++;
	}

	for (const auto &i : col_sums)
		std::cout << std::setw(3) << std::setfill(' ') << i;

	std::cout << std::endl;
}

static void change_cell(const int &row, const int &col, const int &val, std::deque<int> &table)
{
	int cell = (row - 1) * num_cols + (col - 1);

	table.at(cell) = val;
}

static void draw_table(const std::deque<int> &table)
{
	static int col_num = 0;
	static int row_sum = 0;
	static int col_sums[5] = { 0 };

	for (auto cur_col = 0; cur_col < table.size() + 1; cur_col++)
	{
		if (col_num == 5)
		{
			std::cout << std::setw(4) << std::setfill(' ') << row_sum << std::endl;
			col_num = 0;
			row_sum = 0;

			if (cur_col == table.size())
				break;
		}

		row_sum += table.at(cur_col);
		std::cout << std::setw(3) << std::setfill(' ') << table.at(cur_col);

		col_num++;
	}

	std::cout << std::endl;
	calc_vert(table);
	std::cout << std::endl;
}

int main(void)
{
	std::deque<int> num_table(num_cols*num_rows);
	std::fill(num_table.begin(), num_table.end(), 1);
	draw_table(num_table);

	while (true)
	{
		int row = -1, col = -1, val = -1;

		while (row < 1 || col < 1 || val < 0)
		{
			std::cout << "row [1-5]: ";
			if (!(std::cin >> row) || std::cin.fail() || row < 1 || row > 5)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			std::cout << "colum [1-5]: ";
			if (!(std::cin >> col) || std::cin.fail() || col < 1 || col > 5)
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}

			std::cout << "value: ";
			if (!(std::cin >> val) || std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			change_cell(row, col, val, num_table);
		}
		std::cout << std::endl;
		draw_table(num_table);
	}

	return EXIT_SUCCESS;
}