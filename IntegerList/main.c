#include "IntegerList.h"
#include "LinkedIntegerList.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ExecuteIntegerList(void);

void ExecuteLinkedIntegerList(void);

int main(int argc, const char* args[], const char* env[] )
{
	ExecuteIntegerList();
}


void ExecuteIntegerList(void)
{
#pragma warning( suppress : 4244 )
	srand(time(NULL));

	printf("starting integer list test\n");

	IntegerList* myList;
	List_Create(&myList, 8);

	for (int i = 0; i < 16; i++)
	{
		List_Append(myList, i);
	}

	printf("*********************\n");
	printf("appended 16 elements\n");
	printf("*********************\n");

	for (int i = 0; i < 16; i++)
	{
		printf("element at %i = %i\n", i, List_GetAt(myList, i));
	}

	for (int i = 0; i < 8; i++)
	{
		List_InsertAt(myList, 2 * i, 100 * (i + 1));
	}

	printf("*********************\n");
	printf("inserted 8 elements\n");
	printf("*********************\n");

	for (int i = 0; i < 24; i++)
	{
		printf("element at %i = %i\n", i, List_GetAt(myList, i));
	}

	for (int i = 4; i < 8; i++)
	{
		List_RemoveAt(myList, i);
		printf("actual count = %i\n", myList->Count);
	}


	printf("*********************\n");
	printf("removed 4 elements\n");
	printf("*********************\n");

	for (int i = 0; i < 24; i++)
	{
		printf("element at %i = %i\n", i, List_GetAt(myList, i));
	}
	List_Release(myList);
}


void ExecuteLinkedIntegerList(void)
{
	#pragma warning( suppress : 4244 )
	srand(time(NULL));

	printf("starting integer list test\n");

	LinkedIntegerList* myList;
	LinkedList_Create(&myList);

	for (int i = 0; i < 16; i++)
	{
		LinkedList_Append(myList, i);
	}

	printf("*********************\n");
	printf("appended 16 elements\n");
	printf("*********************\n");

	for (int i = 0; i < 16; i++)
	{
		printf("element at %i = %i\n", i, LinkedList_GetAt(myList, i));
	}

	for (int i = 0; i < 8; i++)
	{
		LinkedList_InsertAt(myList, 2 * i, 100 * (i + 1));
	}

	printf("*********************\n");
	printf("inserted 8 elements\n");
	printf("*********************\n");

	for (int i = 0; i < 24; i++)
	{
		printf("element at %i = %i\n", i, LinkedList_GetAt(myList, i));
	}

	for (int i = 4; i < 8; i++)
	{
		LinkedList_RemoveAt(myList, i);
		printf("actual count = %i\n", myList->Count);
	}


	printf("*********************\n");
	printf("removed 4 elements\n");
	printf("*********************\n");

	for (int i = 0; i < 24; i++)
	{
		printf("element at %i = %i\n", i, LinkedList_GetAt(myList, i));
	}
	LinkedList_Release(myList);
}
