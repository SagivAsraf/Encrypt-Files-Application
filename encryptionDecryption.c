#include "encryptionDecryption.h"
#include "general.h"

/*This method encrypt/decrypt general varriable with use in 3 helper methods*/
void encryptionDecryption(void* generalVarriable, int typeSize, int encryptOrDecryption, const int encryptionDecryptionValue)
{
	char* theEncryptionDecrytionVar = (char*)generalVarriable + typeSize - 1;	//begin from last byte
	/*Encryption*/
	if (encryptOrDecryption == ENCRYPTION) {
		/*Part A encrypt by x+1*/
		encryptionDecryptionXWithXPlus1(theEncryptionDecrytionVar, typeSize,encryptionDecryptionValue);
		/*Part B XOR WITH 1 FOR ALL BITS*/
		encryptionDecryptionXorWith1(theEncryptionDecrytionVar, typeSize, encryptionDecryptionValue);
		/*Part C CIRCLE MOVE*/
		encryptionDecryptionCircleMove(theEncryptionDecrytionVar, ENCRYPTION, typeSize, encryptionDecryptionValue);
	}
	/*Decryption -> just the opposite order of the functions*/
	else {
		/*Part A decrypt by CIRCLE MOVE*/
		encryptionDecryptionCircleMove(theEncryptionDecrytionVar, DECRYPTION, typeSize, encryptionDecryptionValue);
		/*Part B XOR WITH 1 FOR ALL BITS*/
		encryptionDecryptionXorWith1(theEncryptionDecrytionVar, typeSize, encryptionDecryptionValue);
		/*Part C decrypt by x+1*/
		encryptionDecryptionXWithXPlus1(theEncryptionDecrytionVar, typeSize, encryptionDecryptionValue);
	}
}

/*Sub method for part a of the question. repalce between the bit in x and in x+1 of the char*/
void encryptionDecryptionXWithXPlus1(char* theEncryption, const int typeSize, const int encryptionDecryptionValue)
{
	int i;
	for (i = 0; i < typeSize; i++, theEncryption--)
	{
		int bitOfX = getBitFromRight(*theEncryption, encryptionDecryptionValue);
		int bitOfXPlusOne;
		if (encryptionDecryptionValue == 7)
			bitOfXPlusOne = getBitFromRight(*theEncryption, 0);
		else
			bitOfXPlusOne = getBitFromRight(*theEncryption, encryptionDecryptionValue + 1);

		if (bitOfX == bitOfXPlusOne)
		{
			return;  //equals. not changing
		}
		else
		{
			/*example for the idea : index = x = 3*/
			unsigned char mask = 1; // 00000001
			unsigned char mask2 = 1; // 00000001

			mask <<= encryptionDecryptionValue; // mask = 00001000
			if (encryptionDecryptionValue != 7)
			{
				mask2 <<= encryptionDecryptionValue + 1; // mask 2 = 00010000  
			}
			mask = mask | mask2; // mask = 00011000
								 //for example the ecryption equal 01110101
			*theEncryption ^= mask; //after xor --> 011 0 1 101 / so index x = 3 and x + 1 are replaced.
		}
	}
	theEncryption += typeSize; //return to last byte
}

/*Sub method for part b of the question. do xor with 1 for all the */
void encryptionDecryptionXorWith1(char* theEncryption,const int typeSize, const int encryptionDecryptionValue)
{
	int i;
	int j;
	for (i = 0; i < typeSize; i++, theEncryption--)
	{
		unsigned char mask = 1; // 00000001
		for (j = 0; j < NUM_OF_BITS_IN_BYTE; j++) //one byte have 8 bits.
		{
			mask = mask << j;
			*theEncryption ^= mask;
			mask = 1; //each time i have to put mask 1 cause my xor have to be with 1 on all byte.
		}
	}
	theEncryption += typeSize; //return to last byte

}


/*Sub method for circle move . 0 to encrypt 1 to decrypt*/
void encryptionDecryptionCircleMove(char* theEncryption, int encryptOrDecrypt, const int typeSize, const int encryptionDecryptionValue)
{
	int i;
	for (i = 0; i < typeSize; i++, theEncryption--)
	{
		char temp;
		char temp2;
		//if (*x == 0) return; // nothing to move.

		if (encryptOrDecrypt == 0) //encrypt
		{
			temp = *theEncryption << (NUM_OF_BITS_IN_BYTE - encryptionDecryptionValue); // shift left 8-x times.
			temp2 = (unsigned char)*theEncryption >> encryptionDecryptionValue; //shift right x times
		}
		else //decrypt
		{
			temp = (unsigned char)*theEncryption >> (NUM_OF_BITS_IN_BYTE - encryptionDecryptionValue);//shift right 8-x times.
			temp2 = (unsigned char)*theEncryption << encryptionDecryptionValue; //shift left x times.
		}
		*theEncryption = temp ^ temp2;
	}
	theEncryption += typeSize; //return to last byte

}



/*Helper method print for debug.*/
void printAllGeneralVarriable(char* theEncryption, int typeSize)
{
	int i;
	printf("\n");
	for (i = 0; i < typeSize; i++, theEncryption--)
	{
		printCharAsBinary(*theEncryption);
		printf(" ");
	}
}