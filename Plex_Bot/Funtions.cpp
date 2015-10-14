#include "Functions.h"
void copy(int *first, int *last, int *result)
{
	while (first != last) {
		*result = *first;
		++result;
		++first;
	}
}