#include "IntegerList.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>


/**
* internal helper functions
*/

bool AllocateListData(IntegerList* list, uint32_t nrOfElement)
{
	assert(list != 0);
	list->_capacity = nrOfElement;
	list->_data = (int32_t*)malloc(sizeof(int32_t) * nrOfElement);
	return list->_data != 0;
}

/**
* Create an new IntgegerList
*/
void List_Create(IntegerList** list, uint32_t initialCapacity)
{
	IntegerList *pI = (IntegerList*)malloc(sizeof(IntegerList));
	
	assert(pI != NULL);
	pI->Count = 0;
	bool allocated = AllocateListData(pI, initialCapacity);
	assert(allocated);
	*list = pI;
}

/**
* free all resources that are associated with this list
*/
void List_Release(IntegerList* list)
{
	free(list->_data);
	free(list);
}

/**
* add a new element to the list
*/
void List_Append(IntegerList* list, int32_t element)
{
	// @todo
	if (list->Count >= list->_capacity)
	{
		int32_t* p = list->_data;
		AllocateListData(list, list->_capacity * 2);
		memcpy(list->_data, p, list->Count * sizeof(int32_t));
		free(p);
	}
	list->_data[list->Count] = element;
	list->Count++;
}


void List_InsertAt(IntegerList* list, uint32_t index, int32_t element)
{
	// @todo
	int32_t* data = list->_data;
	int32_t* toFree = NULL;
	if (list->Count >= list->_capacity)
	{
		toFree = data;
		AllocateListData(list, list->_capacity * 2);
		if (index > 0)
		{
			memcpy(list->_data, toFree, index * sizeof(int32_t));
		}
	}
	for (uint32_t i = list->Count; i > index; i--)
	{
		list->_data[i] = data[i - 1];
	}
	list->_data[index] = element;
	list->Count++;
	if (toFree != NULL)
	{
		free(data);
	}
}

/**
* remove lement at index
*/
bool List_RemoveAt(IntegerList* list, uint32_t index)
{
	// @todo
	if (index < list->Count)
	{
		for (uint32_t i = index; i < list->Count - 1; i++)
		{
			list->_data[i] = list->_data[i + 1];
		}
		list->Count--;
		return true;

	}
	return false;
}


/**
* get the element at index
*/
int32_t List_GetAt(const IntegerList* list, uint32_t index)
{
	// @todo
	if (index < list->Count)
	{
		return list->_data[index];
	}
	return LONG_MIN;
}


