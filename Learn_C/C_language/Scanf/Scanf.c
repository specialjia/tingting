#define _CRT_SECURE_NO_WARNINGS
#include "Scanf.h"
#include <stdio.h>
#include <stdlib.h>


int input()  // ���ʹ��&
{
	int age;
	float assets;  //�ʲ�
	char pet[30];
	 
	printf("Enter your age, assets, and favorite pet.\n");
	scanf(" %d %f ", &age, &assets);
	scanf("%s", pet);  //�ַ����鲻��Ҫʹ��&
	printf("%d $%.2f %s\n", age, assets, pet);

}

int varwid()  //ʹ�ñ������ֶ�
{
	unsigned width, precision; // ��� ��׼��
	int number = 256;
	double weight = 242.5;  // ����

	printf("Enter a field width: \n");
	scanf("%d", &width);
	printf("The number is : %*d\n", width, number);
	printf("Now enter a width and a precision: \n");
	scanf("%d %d ", &width, &precision);
	printf("Weight = %*.*f\n", width, precision, weight);
	printf("Done!\n");

}

int SkipTwo()  // ���������е�ǰ��������
{
	int n;
	printf("Please enter three integers: \n");
	scanf("%*d %*d %d", &n);
	printf("The last integer was %d\n", n);


}
