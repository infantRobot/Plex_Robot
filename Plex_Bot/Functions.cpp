// 
// 
// 

#include "Functions.h"
void copy(int *first, int *last, int *result)
{
	while (first != last) {
		*result = *first;
		++result;
		++first;
	}
}
/*
//Useful for copying arrarys
void copyArray(int array1[SERVOS / 2], int array2[SERVOS / 2])
{
	for (int i = 0; i < SERVOS / 2; i++)
	{
		array1[i] = array2[i];
	}
}

void copyArray(int array1[SERVOS], int array2[SERVOS])
{
	for (int i = 0; i < SERVOS; i++)
	{
		array1[i] = array2[i];
	}
}

//Overloaded for walking routines
void copyArray(int array1[SERVOS*RWALKSTEPS], int array2[SERVOS*RWALKSTEPS])
{
	for (int i = 0; i < SERVOS *RWALKSTEPS; i++)
	{
		array1[i] = array2[i];
	}
}
//Overloaded for walking routines
void copyArray(int array1[SERVOS*TURNSTEPS], int array2[SERVOS*TURNSTEPS])
{
	for (int i = 0; i < SERVOS * TURNSTEPS; i++)
	{
		array1[i] = array2[i];
	}
}

//Grab the first 5 or last 5 elements in array
void getArrayFive(int toA[SERVOS / 2], int fromA[SERVOS], bool first)
{
	int a = 0;
	//If we do not want to copy the first half we want to copy the last 5. adjust a by 5
	if (!first)
	{
		a = SERVOS/2; 
	}
	for (int i = 0; i < SERVOS / 2; i++)
	{
		toA[i] = fromA[i+a];
	}
}
*/