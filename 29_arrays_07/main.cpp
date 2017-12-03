#include <algorithm>
#include <iostream>

constexpr int arr3_len = 20;
constexpr int num_arr1[10] = { 59, 28, 30, 1, 98, 44, 29, 11, 192, 57 };
constexpr int num_arr2[10] = { 2, 4, 8, 16, 32, 64, 128, 512, 1024, 2048 };

int main(void)
{
	int num_arr3[20] = { 0 };

	std::copy(std::begin(num_arr1), std::end(num_arr1), std::begin(num_arr3));
	std::copy(std::begin(num_arr2), std::end(num_arr2), std::begin(num_arr3) + 10);

	for (const auto &i : num_arr3)
		std::cout << i << std::endl;

	return EXIT_SUCCESS;
}