#include <algorithm>
#include <iostream>
#include <string>

int main(void)
{
	std::string input("placeholder");

	while (!input.empty())
	{
		std::cout << "Please write a line of text: " << std::endl;
		std::getline(std::cin, input);

		auto p = input.find("oli");

		while (p != std::string::npos) {
			input.replace(p, 3, "");
			p = input.find("oli");
		}

		std::cout << input << std::endl;
	}

	return EXIT_SUCCESS;
}