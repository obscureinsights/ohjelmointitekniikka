#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdint.h>
#include <string>
#include <sstream>

int main( void ) 
{
	bool is_running = true;
	int count = 0, input = -1, sum = 0;

	while ( is_running == true )
	{
		std::cout << "Please input a number " << count + 1 << std::endl;
		std::cin >> input;

		if (input == 0)
		{
			std::string answer = "";

			std::cout << "Again? K or k, if you want to start again" << std::endl;

			do {
				std::getline(std::cin, answer);
			} while (answer.empty());

			if (answer.find('K') == 0 || answer.find('k') == 0) {
				sum = 0;
				count = 0;
				input = -1;
			}
			else {
				count = 0;
				is_running = false;
				break;
			}
		}
		else if (input > 0)
		{
			sum += input;
			count += 1;
		}

		if (count > 0)
			std::cout << "You have given " << count << " numbers and their sum is: " << sum << std::endl;
	}

	return EXIT_SUCCESS;
}