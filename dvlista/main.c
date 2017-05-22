/*
 * main.c
 *
 *  Created on: May 16, 2017
 *      Author: rtrk
 */


#include "DoubleLinkedList.h"

int main(void)
{
	EmployeeList list;
//	employee e1 = {"Petar","Bojanic",99};
//	employee e2 = {"Nikola","Jovanovic",89};
//	employee e3 = {"Milan","Bajic",97};
//	employee e4 = {"Boris","Milic",34};
//	employee e5 = {"AAA","Bojic",55};
//	employee e6 = {"BBB","Bojic",55};
//	employee e7 = {"DDDD","Bojic",55};
//	employee e8 = {"JJJ","Bojic",55};
	employee* e1 = malloc(sizeof(employee));
	employee* e2 = malloc(sizeof(employee));
	employee* e3 = malloc(sizeof(employee));
	employee* e4 = malloc(sizeof(employee));
	employee* e5 = malloc(sizeof(employee));
	employee* e6 = malloc(sizeof(employee));
	employee* e7 = malloc(sizeof(employee));

	strcpy(e1->name, "asd");
	EmployeeListCreate(&list);

	EmployeeListInsert(&list, &e1, 0);
	EmployeeListInsert(&list, &e2, 1);
	EmployeeListInsert(&list, &e3, 2);
	EmployeeListInsert(&list, &e4, 3);
	EmployeeListInsert(&list, &e5, 4);
	EmployeeListInsert(&list, &e6, 5);
	EmployeeListInsert(&list, &e7, 6);

	EmployeeListDump(&list);

	EmployeeListDestroy(&list);
	return 0;
}
