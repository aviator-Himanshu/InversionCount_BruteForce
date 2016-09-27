#include "stdafx.h"
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// This code will only work fine with x64 Machines or compilers. 

// To run it on x86 platforms, data size must be reduced. 


void Ex1_Inversion();

int main(int argc, _TCHAR* argv[])
{
	/* Initialization */

	Ex1_Inversion();

	return 0;
}


void Ex1_Inversion()
{
	FILE* InputFile = fopen("IntegerArray.txt", "r+");
	char Buff[1000];
	int inPutNumber1, inPutNumber2;
	int *TotalCharacter = new int[100000]; // Again this has to be modified later to take any number of input
	unsigned int startRun = 0;
	unsigned long long InversionCount = 0; 
  
	while (fgets(Buff, 1000, InputFile) != NULL)
	{
		inPutNumber1 = atoi(Buff);
		TotalCharacter[startRun] = inPutNumber1;
		printf("\r Input NUmber is : %07d  of %d", inPutNumber1, startRun);
		startRun++;
	}
	printf("\n");
	for (int i = 0; i <= 100000 - 2; i++)
	{
		printf("\r Current  NUmber is : %07d  ", i);
		for (int j_Tag = i + 1; j_Tag <= 100000 - 1; j_Tag++)
		{

			if (TotalCharacter[j_Tag] < TotalCharacter[i])
				InversionCount++;
		}
	}
	printf("\nTotal Inversion Count - %lld\n", InversionCount);
}
