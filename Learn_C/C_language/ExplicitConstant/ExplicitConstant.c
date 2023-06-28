#define _CRT_SECURE_NO_WARNINGS
#include "ExplicitConstant.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int ExplicitConstant()
{
	printf("Some number limits for this system: \n");
	printf("Biggest int: %d\n", INT_MAX);
	printf("smallest long long: %lld\n", LLONG_MIN);
	printf("One byte = %d bits on this system.\n", CHAR_BIT);
	printf("Largest double: %e\n", DBL_MAX);
	printf("samllest normal float: %e\n", FLT_MIN);
	printf("float precision = %d digits\n", FLT_DIG);
	printf("float epsilon = %e\n", FLT_EPSILON);
}