// Histogram1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <assert.h>

#define countof(x) sizeof x / sizeof x[0]

char FindMaxFrequentChar(const uint32_t* histogram, uint32_t size);

uint32_t histogram[256];
const char path[] = "C:\\Users\\rolfl\\OneDrive - GIBZ\\HFIE\\StrukturierteProgrammierung\\Übungsmaterial\\";
char pathBuffer[1024];

//int main()
int main(int argc, const char *args[], const char *envP[])
{
	printf("hello world\n");

	strcpy_s(pathBuffer, sizeof pathBuffer, path);
	if (argc > 1) // the first argument is the name of the program
	{
		strcat_s(pathBuffer, sizeof pathBuffer, args[1]);
	}
	else
	{
		strcat_s(pathBuffer, sizeof pathBuffer, "Alice Adventure in Wonderland.txt");
	}

	FILE* f = NULL;
	_set_errno(0);
	errno_t err = fopen_s(&f, pathBuffer, "r");
	if (err != 0)
	{
		printf("the error %i occurred", err);
		return 1;
	}
	assert(f != NULL);
	int ch = getc(f);

	while (ch > EOF)
	{
		// here comes the code for filling the histogram	
		histogram[ch]++;
		ch = getc(f);
	}

	_set_errno(0);
	err = fclose(f);
	assert(err == 0);
	uint16_t j = 0;
	
	for (; j < countof(histogram); j++)
	{
		if (histogram[j] > 0)
		{
			printf("vorkommen des Zeichens '%c' = %i\n", j, histogram[j]);
		}
	}

	printf("häufigstes Zeichen = '%c'", FindMaxFrequentChar(histogram, countof(histogram)));

}

char FindMaxFrequentChar(const uint32_t* histogram, uint32_t size)
{
	assert(size > 0);
	uint32_t maxCount = histogram[0];
	uint32_t maxIndex = 0;
	uint32_t i = 1;
	for (; i < size; i++)
	{
		if (histogram[i] > maxCount)
		{
			maxCount = histogram[i];
			maxIndex = 0;
		}
	}
	return histogram[maxIndex];
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

