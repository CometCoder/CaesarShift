// CaesarShift.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <stdio.h>

using namespace std;

bool loop = false;    //Input for main loop
int choice = 0;       //Choice from loop
string to_cipher;     //String inputted to be ciphered
string decipher;      //String inputted to be deciphered
int key = 0;          //Key to cipher and decipher


int main()
{
	//Print out banner
	cout << "##########################################################################\n";
	cout << "#  _______                                  ______ _     _    ___        #\n";
	cout << "# (_______)                                / _____) |   (_)  / __)  _    #\n";
	cout << "#  _       _____ _____  ___ _____  ____   ( (____ | |__  _ _| |__ _| |_  #\n";
	cout << "# | |     (____ | ___ |/___|____ |/ ___)   \\____ \\|  _ \\| (_   __|_   _) #\n";
	cout << "# | |_____/ ___ | ____|___ / ___ | |       _____) ) | | | | | |    | |_  #\n";
	cout << "#  \\______)_____|_____|___/\\_____|_|      (______/|_| |_|_| |_|     \\__) #\n";
	cout << "#                                                                        #\n";
	cout << "##########################################################################\n";
	//Done with that

	//Loop menu with incorrect input handling
	do
	{ 
		//Input and handle input of wrong type or range
		while (cout << "Enter Option #\n\n" << setw(20) << "1. Cipher" << setw(20) << "2. Decipher" << setw(20) << "3. Exit\n" 
			&& !(cin >> choice)   //If cin fails
			|| choice > 3         //If choice is too large
			|| choice < 1)        //If choice is too small
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
			cout << "\nInvalid input. Please enter 1-3 for menu selection.\n";
		}

		//Process input for string & key
		if (choice == 1)
		{
			//Clear characters
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//Make sure input is correct for string
			while (cout << "\nEnter String to Cipher\n" && !(getline(cin, to_cipher))) 
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
				cout << "\nInvalid input. Please enter a string to be ciphered.\n";
			}

			//Get Key and make sure input is correct
			//Make sure input is correct
			while (cout << "\nEnter Key:  " && !(cin >> key)
				|| (key < 1)
				|| (key > 25))
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
				cout << "\nInvalid input. Please enter a number between 1-25\n";
			}

			//Cipher and return data
			cout << "\nCiphering...\n";
			for (int i = 0; i < to_cipher.length(); i++)
			{
				//only shift letters
				if (to_cipher[i] >= 'A' && to_cipher[i] <= 'z')
				{
					//Shift uppercase first
					if (to_cipher[i] >= 'A' && to_cipher[i] <= 'Z')
					{
						//add key to cipher
						to_cipher[i] += key;
						//check if restarting to 'A' is needed (over 90 ascii)
						if (to_cipher[i] > 90)
						{
							to_cipher[i] -= 26;     //26 is magic number to correct going over 90
						}
					}

					//Shift lowercase
					if (to_cipher[i] >= 'a' && to_cipher[i] <= 'z')
					{
						//add key to cipher, using temp so that ascii doesn't go over 127 and into extended range
						int temp = to_cipher[i] + key;
						//check if we need to resetart to 'a' (over ascii 97)
						if (temp > 122)
						{
							to_cipher[i] = temp - 26;   //26 is magic number to correct going over 122
						}
						else 
						{
							//otherwise just assign the new ascii value
							to_cipher[i] = temp;
						}
					}
				}
			}
			cout << "\n" << to_cipher << "\n";
		}
		else if (choice == 2)
		{
			//Clear characters
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			//Make sure input is correct for string
			while (cout << "\nEnter String to Decipher\n" && !(getline(cin, decipher)))
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
				cout << "\nInvalid input. Please enter a string to be deciphered.\n";
			}

			//Get Key and make sure input is correct
			//Make sure input is correct
			while (cout << "\nEnter Key:  " && !(cin >> key)
				|| (key < 1)
				|| (key > 25))
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
				cout << "\nInvalid input. Please enter a number between 1-25\n";
			}

			//Cipher and return data
			cout << "\nDeciphering...\n";
			for (int i = 0; i < decipher.length(); i++)
			{
				//only shift letters
				if (decipher[i] >= 'A' && decipher[i] <= 'z')
				{
					//Shift uppercase first
					if (decipher[i] >= 'A' && decipher[i] <= 'Z')
					{
						//add key to cipher
						decipher[i] -= key;
						//check if restarting to 'A' is needed (less than 65 ascii)
						if (decipher[i] < 'A')
						{
							decipher[i] += 26;     //26 is magic number to correct ascii code
						}
					}

					//Shift lowercase
					if (decipher[i] >= 'a' && decipher[i] <= 'z')
					{
						//add key to cipher, using temp so that ascii doesn't go over 127 and into extended range
						int temp = decipher[i] - key;
						//check if we need to correct going < 97
						if (temp < 'a')
						{
							decipher[i] = temp + 26;   //26 is magic number to correct going over 122
						}
						else
						{
							//otherwise just assign the new ascii value
							decipher[i] = temp;
						}
					}
				}
			}
			cout << "\n" << decipher << "\n";
		}
		else 
		{
			//Exit program (Without system("PAUSE");)
			//TODO: make cross platform solution
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard '\n'
			cout << "Press any key to continue...";
			_getch();
		}

	} while (choice != 3);

	//system("PAUSE");
    return 0;
}