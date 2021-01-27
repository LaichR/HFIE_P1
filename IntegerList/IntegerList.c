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
}


void List_InsertAt(IntegerList* list, uint32_t index, int32_t element)
{
	// @todo
}

/**
* remove lement at index
*/
bool List_RemoveAt(IntegerList* list, uint32_t index)
{
	// @todo
	return true;
}


/**
* get the element at lindex
*/
int32_t List_GetAt(const IntegerList* list, uint32_t index)
{
	// @todo
	return LONG_MIN;
}


