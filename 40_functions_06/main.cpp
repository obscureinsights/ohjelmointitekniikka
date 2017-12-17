#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <string>

/*
Tee ohjelma, joka sijoittaa alustusvaiheessa 10 kokonaislukua 10-alkioiseen taulukkoon.
Lis�ksi ohjelma pyyt�� yhden kokonaisluvun �etsittava� ja ohjelma selvitt��, l�ytyyk� �etsittava� taulukosta.
Jos l�ytyy se poistetaan ja kaikkia �etsittava�:n  j�lkeen tulevia taulukon alkioita siirret��n yksi elementti kohti 0-elementti�. Taulukon loppuun sijoitetaan arvo 0.
Lopuksi taulukko tulostetaan.
- taulukon alustus suoritetaan funktiossa "alusta"
- etsitt�v� luku luetaan omassa funktiossaan "pyydaLuku", joka palauttaa saamansa luvun
- etsi-funktio selvitt��, l�ytyyk� etsittava taulukosta. Jos l�ytyy, palauttaa indeksin, mist� l�ytyy. Jos ei l�ydy, palauttaa taulukon koon tai -1:n.
- poista-funktio poistaa luvun ja siirt�� per�ss� olevia kohti poistettua ja t�ytt�� viimeisen paikan 0:lla
- tulosta-funktio tulostaa taulukon sis�ll�n

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