#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>

int main(void)
{
	std::string user_inp;
	
	int num_found = 0;
	
	do
	{
		std::cout << "Write a line of text" << std::endl;
		std::getline(std::cin, user_inp);

		for (auto i = 0; i < user_inp.length(); ++i)
		{
			const uint8_t &c = user_inp.at(i);
			num_found = 0;

			switch (static_cast<int>(c))
			{
			case 132:
				user_inp.replace(i, 1, "a");
				num_found += 1;
				break;
			case 142:
				user_inp.replace(i, 1, "A");
				num_found += 1;
				break;
			case 148:
				user_inp.replace(i, 1, "o");
				num_found += 1;
				break;
			case 153:
				user_inp.replace(i, 1, "O");
				num_found += 1;
				break;
			default:
				break;
			}
		}
		if( num_found > 0 )
			std::cout << user_inp << std::endl;
		else
			break;
	}while( num_found != 0 );
	
	system("pause");

	return EXIT_SUCCESS;
}