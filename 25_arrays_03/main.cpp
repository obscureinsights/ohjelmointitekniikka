#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>

int main( void )
{
	constexpr int num_array[10] = { 45, 5, 10, 3, 90, 4, 11, 58, 4, 98 };

	const auto high_val = *std::max_element( num_array, num_array + 10 );
	const auto high_idx = std::distance( num_array, std::max_element(num_array, num_array + 10 ));

	std::cout << "Largest number in array: " << high_val << " in index: " 
		<< high_idx << std::endl;

	system("pause");

	return EXIT_SUCCESS;
}