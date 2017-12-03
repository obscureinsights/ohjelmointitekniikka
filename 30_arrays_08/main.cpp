#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>

constexpr int arr3_len = 20;
constexpr int num_arr1[10] = { 59, 28, 30, 1, 98, 44, 29, 11, 192, 57 };
constexpr int num_arr2[10] = { 2, 4, 8, 16, 32, 64, 128, 512, 1024, 2048 };

int main(void)
{
	int num_arr3[20] = { 0 };

	static int arr_idx = 0, count = 0;

	while( arr_idx < arr3_len )
	{
		num_arr3[arr_idx]   = num_arr1[count];
		num_arr3[arr_idx+1] = num_arr2[count];
		
		arr_idx += 2;
		count++;
	}
	
	for (const auto &i : num_arr3)
		std::cout << i << std::endl;

	std::cin.get();

	return EXIT_SUCCESS;
}