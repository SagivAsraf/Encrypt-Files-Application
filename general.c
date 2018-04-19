#include "general.h"

/*Helper method to set bit 0/1 from right (index)*/

void setBitFromRight(unsigned char* ch, int index, int value)
{
	unsigned char mask = 1; // 00000001
	mask <<= index;
	if (value == 1)
		*ch = *ch | mask;
	else
	{
		mask = ~mask;
		*ch = *ch & mask;
	}
}

/*Helper method to get bit 0/1 from right (index)*/

int getBitFromRight(unsigned char ch, int index)
{
	unsigned char mask = 1; // 00000001
	mask = mask << index;
	if ((ch & mask) == 0)
		return 0;
	else
		return 1;
}

void printCharAsBinary(char ch)
{
	int i;
	unsigned char temp;
	for (i = 0; i < 8; i++)
	{
		temp = ch << i;
		temp = temp >> 7;
		printf("%d", temp);
	}
}


