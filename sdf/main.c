#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


#define ARRAY_SIZE 999

static int* parray[ARRAY_SIZE];

static int comp(const void* x, const void* y)
{
	ptrdiff_t res = *(int**)x - *(int**)y;
	return res;
}

void main()
{
	int i;
	int* temp;

	for (i = 0; i < ARRAY_SIZE/3; i++)
	{
		parray[i] = (int*)malloc(sizeof(int));
		*(parray[i]) = i;
	}

	//
	temp = (int*)malloc(sizeof(int));

	for (i = ARRAY_SIZE/3; i < 2*(ARRAY_SIZE/3); i++)
	{
		parray[i] = (int*)malloc(sizeof(int));
		*(parray[i]) = i;
	}

	//
	free(temp);
	//temp = (int*)malloc(sizeof(int));

	for (i = 2*(ARRAY_SIZE/3); i < ARRAY_SIZE; i++)
	{
		parray[i] = (int*)malloc(sizeof(int));
		*(parray[i]) = i;
	}

//	free(temp);

	qsort(parray,ARRAY_SIZE , sizeof(int*), comp);

	for (i = 0; i < ARRAY_SIZE; i++)
	{
		printf("%d ", *(parray[i]));
	}
	printf("\n");
	for (i = 0; i < (ARRAY_SIZE - 1); i++)
	{
		if (*(parray[i]) > *(parray[i + 1]))
			printf("Ovde: %d, %d\n", *(parray[i]), *(parray[i + 1]));

	}
//	printf("%d",sizeof(int*));
}
