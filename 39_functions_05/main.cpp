#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

constexpr int arr_len = 10;

int find_largest( int num_arr[], int &largest )
{
	static int hi_num = 0, hi_idx = 0;

	for (auto i = 0; i < arr_len; i++)
	{
		if (num_arr[i] > hi_num) {
			hi_idx = i;
			hi_num = num_arr[i];
		}
	}
	return hi_idx;
}

void print_array(int num_arr[])
{
	for (auto i = 0; i < arr_len; i++)
		std::cout << num_arr[i] << std::endl;
}

void setup_array( int num_arr[] )
{
	for( auto i = 0; i < arr_len; i++ )
		num_arr[i] = rand() % 128; 
}

int main(void)
{
	srand(::time_t(0));

	int num_arr[arr_len];

	setup_array(num_arr);
	print_array(num_arr);

	auto largest_num = 0;
	auto largest_idx =  find_largest(num_arr, largest_num);

	std::cout << "Biggest number in array: " << num_arr[largest_idx] << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}