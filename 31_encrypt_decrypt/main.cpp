#include <algorithm>
#include <clocale>
#include <iomanip>
#include <iostream>
#include <string>
#include <stdint.h>

const std::string dec = "abcdefghijklmnopqrstuvwxyzåäö";
const std::string key = "enuczkpxorjtdålwgsböhayqäivmf";

static void decrypt_encrypt( std::string &in, const bool &encrypt = false )
{
	auto p = std::string::npos;

	for( auto i = 0; i < in.length(); i++ )
	{
		const auto c = in.at(i);
		
		if (!encrypt) {
			p = key.find(c);
			if( p != std::string::npos )
				in.at(i) = dec.at(p);
		}
		else {
			p = dec.find(c);
			if (p != std::string::npos)
				in.at(i) = key.at(p);
		}
	}
}

static void draw_menu( int state )
{
	system("cls");

	if( state == 0 )
	{
		std::cout << std::endl << "Select action to perform" << std::endl;
		std::cout << " " << std::setfill('*') << std::setw(16) << "" << std::endl;
		std::cout << " *" << " 1. Decrypt" << std::setfill(' ') << std::setw(4) << "*" << std::endl;
		std::cout << " *" << " 2. Encrypt" << std::setfill(' ') << std::setw(4) << "*" << std::endl;
		std::cout << " *" << " 3. Exit   " << std::setfill(' ') << std::setw(4) << "*" << std::endl;
		std::cout << " " << std::setfill('*') << std::setw(16) << "" << std::endl;
	}
	else if( state == 1 )
	{
		std::cout << "Please enter encrypted text to decrypt: ";
	}
	else if( state == 2 )
	{
		std::cout << "Please enter text to encrypt: ";
	}
}

int main( void )
{
	std::setlocale( LC_ALL, "fi-FI" );

	static int state = 0;
	
	draw_menu(0);

	while( true )
	{
		if( state < 0 || state > 3 )
			state = 0;

		draw_menu(state);

		if (state == 0)
		{
			if (!(std::cin >> state) || std::cin.fail() ) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
		}
		else if( state == 1 )
		{
			std::string encrypted;
			std::getline( std::cin, encrypted );

			if( encrypted.empty() )
				continue;

			decrypt_encrypt(encrypted);

			std::cout << "Decrypted: [" << encrypted << "]" << " press any key to continue..." << std::endl;
			std::cin.get();
			state = 0;
		}
		else if (state == 2)
		{
			std::string input;
			std::getline( std::cin, input );

			if( input.empty() )
				continue;

			decrypt_encrypt(input, true);

			std::cout << "Encrypted: [" << input << "]" << " press any key to continue..." << std::endl;
			std::cin.get();
			state = 0;
		}
		else if(state == 3)
			break;
	}
	system("pause");

	return EXIT_SUCCESS;
}