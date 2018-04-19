#ifndef __FILE_H
#define __FILE_H
#pragma warning (disable:4996)

#include <stdarg.h>
#include "encryptionDecryption.h"
#include <time.h>   // for 'time'
#include <string.h>

void EncryptOrDecryptFile(char* txtSourceFile,const int encryptOrDecrypt,const int encryptDecryptKey);
void isFileExist(char* textSourceFile);
#endif
