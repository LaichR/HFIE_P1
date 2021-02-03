#include "LinkedIntegerList.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>


IntegerListNode* CreateNode(int32_t value)
{
	IntegerListNode* p = (IntegerListNode*)malloc(sizeof(IntegerListNode));
	assert(p != NULL);
	p->value = value;
	return p;
}

void MoveToNode(const LinkedIntegerList* list, 
	uint32_t index, IntegerListNode** p, IntegerListNode** q)
{
	
	IntegerListNode*  _q = (IntegerListNode *)&list->Sentinel;
	IntegerListNode* _p = _q->_next;
	uint32_t currentPosition = 0;
	while (_p != &list->Sentinel && currentPosition < index)
	{
		_q = _p;
		_p = _p->_next;
		currentPosition++;
	}
	*p = _p; *q = _q;
}

/**
* Create an new IntgegerList
*/
void LinkedList_Create(LinkedIntegerList** list)
{
	LinkedIntegerList* p = (LinkedIntegerList*)malloc(sizeof(LinkedIntegerList));
	assert(p != NULL);
	p->Count = 0;
	p->Sentinel._next = &p->Sentinel;
	*list = p;
}

/**
* free all resources that are associated with this list
*/
void LinkedList_Release(LinkedIntegerList* list)
{
	assert(list != NULL);
	IntegerListNode* p = list->Sentinel._next;
	IntegerListNode* q = p;
	while (p != &list->Sentinel)
	{
		q = p;
		p = p->_next;
		free(q);
	}
}

/**
* add a new element to the list
*/
void LinkedList_Append(LinkedIntegerList* list, int32_t element)
{
	IntegerListNode *p, *q;
	MoveToNode(list, list->Count, &p, &q);
	IntegerListNode* newNode = CreateNode(element);
	q->_next = newNode;
	newNode->_next = p;
	list->Count++;
}

/**
* add a new element to the list
*/
void LinkedList_InsertAt(LinkedIntegerList* list, uint32_t index, int32_t element)
{
	IntegerListNode* p, * q;
	MoveToNode(list, index, &p, &q);
	IntegerListNode* newNode = CreateNode(element);
	q->_next = newNode;
	newNode->_next = p;
	list->Count++;
}


/**
* remove lement at index
*/
bool LinkedList_RemoveAt(LinkedIntegerList* list, uint32_t index)
{
	if (list->Count > index)
	{
		IntegerListNode* p, * q;
		MoveToNode(list, index, &p, &q);
		IntegerListNode* toFree = q->_next;
		q->_next = p->_next;
		free(toFree);
		list->Count--;
	}
	return false;
}


/**
* get the element at index
*/
int32_t LinkedList_GetAt(const LinkedIntegerList* list, uint32_t index)
{
	if (index < list->Count)
	{
		IntegerListNode* p, * q;
		MoveToNode(list, index, &p, &q);
		return p->value;
	}
	return LONG_MIN;
}



