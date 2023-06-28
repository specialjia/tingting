#define _CRT_SECURE_NO_WARNINGS
#include "do while.h"
#include <stdio.h>
#include<stdlib.h>
#define ROWS 6
#define CHARS 10

int do_while()
{
	const int secret_code = 13;
	int code_entered;
	do
	{
		printf("To enter the triskaidekaphobia therapy club,\n");
		printf("Please enter the secret code number:");
		scanf("%d", &code_entered);

	} while (code_entered != secret_code);
	printf("Congratulations! You are cured!\n");

}

int rowsl()  //Ç¶Ì×Ñ­»·
{
	int row;
	char ch;
	for (row = 0; row < ROWS; ++row)
	{
		for (ch = 'A'; ch < ('A' + CHARS); ++ch)
		{
			printf("%c", ch); 
		}
		printf("\n");

	}
}

int rows()
{
	const int ROW = 6;
	const int CHAR = 6;
	int row;
	char ch;
	for (row = 0; row < ROW; ++row)
	{
		for (ch = ('A' + row); ch<('A' + CHAR); ++ch)  
			printf("%c", ch);
		printf("\n");
	}

}