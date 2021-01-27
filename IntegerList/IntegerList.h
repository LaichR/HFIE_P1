#pragma once

#include <stdint.h>
#include <stdbool.h>


typedef struct
{
	uint32_t Count;			//< number of elements actually stored in the list
	uint32_t _capacity;		//< number of elements that can be stored before in the currently allocated array
	int32_t *_data;			//< actual data store
}IntegerList;

/**
* Create an new IntgegerList
*/
void List_Create(IntegerList** list, uint32_t initialCapacity);

/**
* free all resources that are associated with this list
*/
void List_Release(IntegerList* list);

/**
* add a new element to the list
*/
void List_Append(IntegerList* list, int32_t ement);

/**
* add a new element to the list
*/
void List_InsertAt(IntegerList* list, uint32_t index, int32_t ement);


/**
* remove lement at index
*/
bool List_RemoveAt(IntegerList* list, uint32_t index);


/**
* get the element at lindex
*/
int32_t List_GetAt(const IntegerList* list, uint32_t index);


