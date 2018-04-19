#pragma warning (disable:4996)

#include "encryptionDecryption.h"
#include "file.h"


void getInputFromUser(char* theFileName, int* encryptOrDecrypt, int* encryptValue);

void main(int  argc, char*  argv[])
{
	char theFileName[200];//maximun 200 chars for full paths if we need it.
	int encryptOrDecrypt; //0->encrypt 1->decrypt
	int encryptDecryptValue;//-> encrypt value to encrypt/decrypt by. 1-7.

	getInputFromUser(theFileName, &encryptOrDecrypt, &encryptDecryptValue);

	EncryptOrDecryptFile(theFileName, encryptOrDecrypt, encryptDecryptValue);  //"M:\\heyJudeE.txt"
	
	system("PAUSE");

}

/*Helper method for get input from the user*/
void getInputFromUser(char* theFileName, int* encryptOrDecrypt, int* encryptValue) {

	printf("Hello, please enter the (TXT) file name that you want to Encrypt/Decrypt --> FULL Path is required!\n");
	scanf("%s", theFileName);
	/*Check if the file exist and can read/write to it*/
	isFileExist(theFileName);/*If not - program exit*/
	
	do {
		printf("For encrypt press 0 || for decrypt press 1\n");
		scanf("%d", encryptOrDecrypt);
	} while (*encryptOrDecrypt != 0 && *encryptOrDecrypt != 1);

	do
	{
		printf("What is your encryption key? (1-7) \n \t\t\t\ //************NOTE************// \n \t\tYou have to remmember/keep this number for decrypt your data.\n");
		scanf("%d", encryptValue);
	} while (*encryptValue>7 || *encryptValue<1);

}