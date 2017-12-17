#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

/*
Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon.
Lisäksi ohjelma pyytää yhden kokonaisluvun ”etsittava” ja ohjelma selvittää, löytyykö ”etsittava” taulukosta.
Jos löytyy se poistetaan ja kaikkia ”etsittava”:n  jälkeen tulevia taulukon alkioita siirretään yksi elementti kohti 0-elementtiä. Taulukon loppuun sijoitetaan arvo 0.
Lopuksi taulukko tulostetaan.
- taulukon alustus suoritetaan funktiossa "alusta"
- etsittävä luku luetaan omassa funktiossaan "pyydaLuku", joka palauttaa saamansa luvun
- etsi-funktio selvittää, löytyykö etsittava taulukosta. Jos löytyy, palauttaa indeksin, mistä löytyy. Jos ei löydy, palauttaa taulukon koon tai -1:n.
- poista-funktio poistaa luvun ja siirtää perässä olevia kohti poistettua ja täyttää viimeisen paikan 0:lla
- tulosta-funktio tulostaa taulukon sisällön

*/
constexpr int arr_len = 10;

int find_num( const std::deque<int> &num_arr, const int &num_to_find )
{
	for ( auto i = 0; i < num_arr.size(); i++ )
	{
		if( num_arr.at(i) == num_to_find )
			return i;
	}

	return -1;
}

int read_find( void )
{
	int num_to_find = -1;

	while ( num_to_find < 0 )
	{
		std::cout << "Type a number to find from array: ";

		if (!(std::cin >> num_to_find) || std::cin.fail() || num_to_find < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}

	return num_to_find;
}

void remove_from_array( std::deque<int> &num_arr, const int &index )
{
	num_arr.erase(num_arr.begin() + index );
	num_arr.emplace_back(0);
}

void print_array( const std::deque<int> &num_arr )
{
	for ( const auto &i : num_arr )
		std::cout << i << std::endl;
}

void setup_array( std::deque<int> &num_arr )
{
	for (auto i = 0; i < arr_len; i++)
		num_arr.push_back( rand() % 128 );
}

int main(void)
{
	srand(::time_t(0));
	std::deque<int> num_array;

	setup_array(num_array);
	
	//print_array(num_array);
	auto num_to_find = read_find();

	if( num_to_find != -1 )
	{
		auto index = find_num( num_array, num_to_find );

		if( index != -1)
		{
			remove_from_array( num_array, index );
		}
	}
	
	print_array(num_array);

	system("pause");

	return EXIT_SUCCESS;
}