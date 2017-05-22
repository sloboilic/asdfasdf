/*
 * DoubleLinkedList.c
 *
 *  Created on: May 16, 2017
 *      Author: rtrk
 */


#include "DoubleLinkedList.h"


// Creates empty EmployeeList
int EmployeeListCreate(EmployeeList* list)
{
	list->head = list->tail = NULL;
	list->size = 0;
	return 1;
}


// Frees all memory allocated by list
void EmployeeListDestroy(EmployeeList* list)
{
	if (!(list->size)) return;
	employee * current;
	current = list->tail;
	while (current != list->head)
	{
		current = current->prev;
		free(current->next);
	}
	free(current);
	list->head = list->tail = NULL;
	list->size = 0;
}


//Function inserts employee element to specific position (index) in the list
int EmployeeListInsert(EmployeeList* list, employee* element, int index)
{
	if ((index > list->size) || (index < 0)) return 0;

	if (!index)
	{


		if(list->size>0){  //pogurati ovog sto je ispred njega
					list->head->prev=element;
					element->next=(*list).head;
				}else{
					(*list).tail=element;
				}
				(*list).head=element;//ako je index 0, poslavi element za head liste
				(*element).prev=NULL;

				(*list).size++;

		return 1;
	}

	if (index == list->size)
	{
		element->prev=list->tail;
		list->tail->next=element;
		list->tail=element;
	//	(*list).tail=element;
		(*element).next=NULL;
		(*list).size++;
		return 1;

	}


	employee* current;
		int i;
		current=list->head;
		for(i=0;i<index;i++)current=current->next;
		element->prev=current->prev;
		current->prev->next=element;
		element->next=current;
		current->prev=element;
		list->size++;
		return 1;



}


//Function deletes employee element from specific position(index) in the list
int EmployeeListDelete(EmployeeList* list, int index)
{
	return 1;
}


// Function returns employee element at specific position (index) in the list
employee* EmployeeListGetElement(EmployeeList* list, int index)
{
	if ((index >= list->size) || (index < 0)) return NULL;

	if (!index)
	{
		return list->head;
	}

	if (index == (list->size-1))
	{
		return list->tail;
	}

	employee * current;
	int i;

	if (index < (list->size - index))
	{
		current = list->head->next;
		for (i = 1; i < index; current = current->next , i++);
		return current;
	}
	else
	{
		current = list->tail->prev;
		for (i = (list->size - 2); i > index; current = current->prev , i--);
		return current;
	}
}


//Function returns number of elements in the list
int EmployeeListSize (EmployeeList* list)
{
	return list->size;
}


// Prints all list elements on standard out
void EmployeeListDump (EmployeeList* list)
{
	if (!(list->size)) return;
	employee * current;
	current = list->head;
	do
	{
		printf("NAME:       %s", current->name);
		printf("\n");
		printf("GROUP:      %s", current->group);
		printf("\n");
		printf("EXPERIENCE: %f", current->experience);
		printf("\n");
		current = current->next;
	}
	while (current != NULL);
}
