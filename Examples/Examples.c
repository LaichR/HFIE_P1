// Examples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

uint32_t BitshiftLeft(uint32_t nr, uint8_t pos);


char* AllocAndPtrint(const char* str);

uint32_t Quersumme(uint32_t val)
{
	uint32_t qs = 0;
	while (val != 0)
	{
		qs = qs + val % 10;
		val = val/10;
	}
	return qs;
}

uint32_t Summe(const int32_t* values, uint32_t nrOfValues)
{
	assert(values != NULL);
	assert(nrOfValues > 0);
	uint32_t sum = 0;
	uint32_t i = 0;
	for (; i < nrOfValues; i++)
	{
		sum += values[i];
	}
	return sum;
}

void Swap(int32_t* left, int32_t* right)
{
	int32_t tmp = *left;
	*left = *right;
	*right = tmp;
}

char buffer[256];

char* ReadNextWord(const char* data, uint32_t* curIndex, uint16_t maxLen)
{

	uint32_t i = *curIndex;
	
	uint16_t j = 0;
	//
	// skip non alphanumeric characters
	while (i< maxLen && !isalpha(data[i])) i++;
	
	//
	if (i == maxLen)
	{
		*curIndex = i;
		return NULL;
	}
	
	// now read the word
	while (i < maxLen && isalpha(data[i]))
	{
		buffer[j++] = data[i++];
	}

	// fill in the 0 termination
	buffer[j] = '\0';
	char* newWord = (char*)malloc(j+1);
	assert(newWord != NULL);
	strcpy_s(newWord, j+1, buffer);

	// give out the current index; the string is processed up to here
	*curIndex = i;
	return newWord;
}

uint32_t ParseWords(char* table[], uint32_t maxNumberOfEntries, const char* wordList)
{
	uint32_t wordListLength = strnlen(wordList, 1024);
	uint32_t curIndex = 0;
	uint32_t curEntry = 0;
	while (curIndex < wordListLength && curEntry<maxNumberOfEntries)
	{
		char* newWord = ReadNextWord(wordList, &curIndex, wordListLength);
		if (newWord != NULL)
		{
			table[curEntry] = newWord;
			curEntry++;
		}
	}
	return curEntry;
}

char* table[1024] = { 0 };
int32_t data[1024];
int32_t sizeofData;

int main(int argc, const char* args[], const char* envP[])
{
	if (argc > 2) // i pass the number of the exercice as a parameter on the command line
	{
		if (strcmp(args[1], "4.2a") == 0)
		{
			uint32_t num = atoi(args[2]);
			printf("quersumme von %i = %i\n", num, Quersumme(num));
		}
		else if (strcmp(args[1], "4.2b") == 0)
		{
			sizeofData = argc - 2;
			int32_t i = 0;
			for (; i < sizeofData; i++)
			{
				data[i] = atoi(args[i + 2]);
			}
			printf("summe der eingaben Zahlen: %i\n", Summe(data, sizeofData));
		}
		else if (strcmp(args[1], "4.2c") == 0)
		{
			int32_t left = atoi(args[2]);
			int32_t right = atoi(args[3]);
			printf("before swap left = %i, right = %i\n", left, right);
			Swap(&left, &right);
			printf("after swap left = %i, right = %i\n", left, right);
		}
		else if (strcmp(args[1], "4.2d") == 0)
		{
			printf("received string with list of words: %s\n", args[2]);

			uint32_t nrOfWords = ParseWords(table, _countof(table), args[2]);
			
			uint16_t index = 0;
			for (; index < nrOfWords; index++)
			{
				printf("word %i = %s\n", index, table[index]);
			}
			for (index = 0; index < nrOfWords; index++)
			{
				free(table[index]);
			}
		}
	}
	else
	{
		printf("unsupported command");
	}
}


// this is just an example for malloc and free
// and not part of exercise 4 
char* AllocAndPtrint(const char* str)
{
	printf("AllocAndPtrint: ");

	size_t maxlen = strlen(str) + 1;
	char* mynewString = malloc(maxlen);
	assert(mynewString != 0);
	strcpy_s(mynewString, maxlen, str);
	printf(mynewString);
	printf("\n");
	return mynewString;
}

// this is just an example of the bitschift operator on not part of exercise 4
// 
uint32_t BitshiftLeft(uint32_t nr, uint8_t pos)
{
	uint32_t val = nr << pos;
	printf("bitshift: %i << %i = %i\n", nr, pos, val);
	return val;
}
