#include <algorithm>
#include <iostream>
#include <string>

void find_num_pairs(const std::string &in, std::string &out)
{
	for (const char &c : in)
	{
		if (!::isdigit(c))
			continue;

		const auto &prev = *(&c - 1);
		const auto &next = *(&c + 1);

		if (::isdigit(next) && !::isdigit(prev))
		{
			const auto &third = *(&next + 1);

			if (::isdigit(third))
				continue;

			out += c;
			out += next;
			out += '\n';
		}
	}
}

int main(void)
{
	std::string input("placeholder");
	std::string output;

	while (true)
	{
		std::cout << "Please input a line of text: " << std::endl;

		if (!(std::getline(std::cin, input)) || input.empty())
			break;

		find_num_pairs(input, output);

		if (!output.empty())
			std::cout << output << std::endl;

		output.clear();
	}

	return EXIT_SUCCESS;
}