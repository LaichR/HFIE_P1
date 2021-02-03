#pragma once
#include <stdint.h>
#include <stdbool.h>


typedef struct IntegerListNode_tag
{
	int32_t value;
	struct IntegerListNode_tag* _next;
}IntegerListNode;

typedef struct
{
	uint32_t Count;
	IntegerListNode Sentinel;
}LinkedIntegerList;

/**
* Create an new IntgegerList
*/
void LinkedList_Create(LinkedIntegerList** list);

/**
* free all resources that are associated with this list
*/
void LinkedList_Release(LinkedIntegerList* list);

/**
* add a new element to the list
*/
void LinkedList_Append(LinkedIntegerList* list, int32_t ement);

/**
* add a new element to the list
*/
void LinkedList_InsertAt(LinkedIntegerList* list, uint32_t index, int32_t ement);


/**
* remove lement at index
*/
bool LinkedList_RemoveAt(LinkedIntegerList* list, uint32_t index);


/**
* get the element at lindex
*/
int32_t LinkedList_GetAt(const LinkedIntegerList* list, uint32_t index);

/**
* iterate
*/
bool LinkedList_GetFirst(const LinkedIntegerList* list, IntegerListNode** node);

bool LinkedList_GetNext(const IntegerListNode* list, IntegerListNode** node);


