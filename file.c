#include "file.h"


/*This func read all the information from the file,
	encrypt it or decrypt it by the user request,
	and write the new data back to the file*/
void EncryptOrDecryptFile(char* txtSourceFile, const int encryptOrDecrypt, const int encryptDecryptKey) {

	char* informationToEncrypt = NULL;
	int sizeOfFile = 0;

	isFileExist(txtSourceFile);/*If not - exit program */

	FILE* sourceFile = fopen(txtSourceFile, "r+");

	fseek(sourceFile, 0, SEEK_END); //put the seek on the end of the file
	sizeOfFile = ftell(sourceFile); // check the num of characters we have from the end to the start (size of file)
	rewind(sourceFile);//return the seek to the start of the file

	informationToEncrypt = (char*)malloc(sizeof(char) * sizeOfFile);
	fread(informationToEncrypt, 1, sizeOfFile, sourceFile);

	encryptionDecryption(informationToEncrypt, sizeof(char)*sizeOfFile, encryptOrDecrypt, encryptDecryptKey);

	printf("Now your data is: \n\n %s", informationToEncrypt);
	rewind(sourceFile);
	fwrite(informationToEncrypt, 1, sizeOfFile, sourceFile);

	fclose(sourceFile);
	if (encryptOrDecrypt == 0) { printf("\n\nYoure file encrypted successfully.--> PLEASE dont forger you encryption key: %d \n\n", encryptDecryptKey); }
	else { printf("\n\nYoure file decrypted successfully\n"); }

	free(informationToEncrypt);

}
/*Helper method for check if the file name is legal -> (the file exist on this path!)*/
void isFileExist(char* textSourceFile) {

	FILE* sourceFile;

	sourceFile = fopen(textSourceFile, "r+");

	if (!sourceFile)
	{
		printf("Can't read file! maybe file doesnt exist. check the name and try again... \n");
		system("PAUSE");
		exit(EXIT_FAILURE);
	}
	fclose(sourceFile);

}
