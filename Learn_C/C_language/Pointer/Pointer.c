#include "pointer.h"
#include <stdio.h>
#include <stdlib.h>

int pointer()
{
	int i = 1;
	int* p = &i;  //p = &i
	printf("%d\n", sizeof(i));
	printf("%d\n", sizeof(p));

	printf("i = %d\n", i);
	printf("&i = %p\n", &i);
	printf("p = %p\n", p);
	printf("&P = %p\n", &p);
	printf("*p = %d\n", *p);

	return 0;
}