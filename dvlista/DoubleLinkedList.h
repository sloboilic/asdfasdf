/*
 * DoubleLinkedList.h
 *
 *  Created on: May 16, 2017
 *      Author: rtrk
 */


#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 20
#define GROUP_NAME_SIZE 20

typedef struct employee{
	char 	name[NAME_SIZE];
	char 	group[GROUP_NAME_SIZE];
	float 	experience;
	struct 	employee *prev;
	struct 	employee *next;
} employee;

typedef struct EmployeeList {
	employee* head;  // Pointer to first element in list
	employee* tail;  // Pointer to last element in list
	int 		size;   // Number of elements in list
} EmployeeList;

// Creates empty EmployeeList
int EmployeeListCreate(EmployeeList* list);

// Frees all memory allocated by list
void EmployeeListDestroy(EmployeeList* list);

//Function inserts employee element to specific position (index) in the list
int EmployeeListInsert(EmployeeList* list, employee* element, int index);

//Function deletes employee element from specific position(index) in the list
int EmployeeListDelete(EmployeeList* list, int index);

// Function returns employee element at specific position (index) in the list
employee * EmployeeListGetElement (EmployeeList* list, int index);

//Function returns number of elements in the list
int EmployeeListSize (EmployeeList* list);

// Prints all list elements on standard out
void EmployeeListDump  (EmployeeList* list);

#endif /*DOUBLELINKEDLIST_H_*/
