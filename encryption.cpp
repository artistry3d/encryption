#include <iostream>

using namespace std;

const int SIZE = 12;

struct crypt
{
	char encrypt[SIZE];
	char decrypt[SIZE];
	int offset;
};

struct crypt words;//this had to be done globally. when it was in the main function, there was all sorts of garbage being
		   //printed after the encryption

void encryption(char[], char[], int);

int main()
{
	cout << "Enter string to encrypt: ";
	
	cin.getline(words.encrypt, SIZE);
	//cin.ignore(256, '\n');

	char *ptrEnc, *ptrDec;
	//ptrEnc = words.encrypt;
	ptrDec = words.decrypt;
	
	//calls encryption function
	encryption(words.encrypt, words.decrypt, words.offset);

	//i = 0;
	while (*ptrDec != NULL)
	{
		cout << *ptrDec;
		ptrDec++;
	}

	cout << endl;
	system("pause");
	return 0;
}//end main

//Encrypts string
void encryption(char encrypt[], char decrypt[], int offset)
{
	cout << "Choose a number from 3 to 13: ";
	cin >> offset;

	int i = 0;
	while (encrypt[i] != NULL)
	{
		if (encrypt[i] >= 'a' && encrypt[i] <= 'z')
		{
			if (encrypt[i] + offset > 122)
			{
				decrypt[i] = encrypt[i] + (offset - 26);
			}
			else
			{
				decrypt[i] = encrypt[i] + offset;
			}
		}
		else if (encrypt[i] >= 'A' && encrypt[i] <= 'Z')
		{
			if (encrypt[i] + offset > 90)
			{
				decrypt[i] = encrypt[i] + (offset - 26);
			}
			else
			{
				decrypt[i] = encrypt[i] + offset;
			}
		}
		else
			decrypt[i] = encrypt[i];

		i++;
	}
}//end encryption
