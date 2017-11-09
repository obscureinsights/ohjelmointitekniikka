#include <algorithm>
#include <iostream>
#include <string>

void mess_string(std::string &in)
{
	if (in.length() == 1) {
		in = "The end.";
	}
	else {
		const auto first_char = in.front();
		const auto final_char = in.back();

		if (first_char == final_char)
		{
			in.front() = '*';
			in.back() = '*';
		}
		else
		{
			in.front() = final_char;
			in.back() = first_char;
		}
	}
}

int main(void)
{
	std::string input;
	size_t len = 0;

	do
	{
		std::cout << "Please input word: ";
		std::getline(std::cin, input);

		len = input.length();

		if (len == 0)
			continue;

		mess_string(input);

		if (len != 1)
			std::cout << "Looks like you didn't input the word: " << input << std::endl;

	} while (len != 1);

	std::cout << input << std::endl;

	return EXIT_SUCCESS;
}