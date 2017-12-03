#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
/*
Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon ja lajittelee taulukon siten, 
että alkiot ovat taulukossa laskevassa järjestyksessä.
*/

int main(void)
{
	std::deque<int> int_array = { 32, 12, 4, 6, 128, 77, 3, 1, 99, 22 };

	std::sort( int_array.begin(), int_array.end(), std::greater<int>() );

	for (const auto &i : int_array)
	{
		std::cout << i << std::endl;
	}

	std::cin.get();
	
	return EXIT_SUCCESS;
}