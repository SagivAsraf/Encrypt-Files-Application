#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>


#define NUM_OF_BITS_IN_BYTE 8
#define ENCRYPTION 0
#define DECRYPTION 1

void encryptionDecryption(void* generalVarriable, int typeSize, int encryptOrDecryption,const int encryptionDecryptionValue);
void encryptionDecryptionXWithXPlus1(char* theEncryption, const int typeSize, const int encryptionDecryptionValue);
void encryptionDecryptionXorWith1(char* theEncryption, const int typeSize, const int encryptionDecryptionValue);
void encryptionDecryptionCircleMove(char* theEncryption, int encryptOrDecrypt,const int typeSize, const int encryptionDecryptionValue);
void printAllGeneralVarriable(char* theEncryption,int typeSize);
