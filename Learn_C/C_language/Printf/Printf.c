#define _CRT_SECURE_NO_WARNINGS
#include "Printf.h"
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141593
#define PAGES 959
#define BLURB "Authentic imitation!"
#define PAGES1 336
#define WORDS 65618




int Printf()
{
	int number = 7;
	float pies = 12.75;
	int cost = 7800;

	printf("The %d contestants ate %f berry pies.\n", number, pies);
	printf("The value of pi is %f.\n", PI);
	printf("Farewell! thou art too dear for my possessing,\n");
	printf("%c%d\n", '$', 2 * cost);

}
int width() // �ֶο��
{
	printf("*%d*\n", PAGES);
	printf("*%2d*\n", PAGES);
	printf("*%10d*\n", PAGES);  //	ռ10���ո���,�Ҷ���
	printf("*%-10d*\n", PAGES); // ռ10���ո���, �����

}

int floats()
{
	const double RENT = 3852.99;//const�޶���,rent(���)�ڳ����в��ɸ���
	printf("*%f*\n", RENT);  
	printf("*%e*\n", RENT);
	printf("*%4.2f*\n", RENT);
	printf("*%3.1f*\n", RENT);
	printf("*%10.3f*\n", RENT);
	printf("*%10.3e*\n", RENT);
	printf("*%+4.2f*\n", RENT);
	printf("*%010.2f*\n", RENT);

}

int flags()  // ���
{
	printf("%x %X %#x\n", 31, 31, 31);
	printf("**%d**% d**% d**\n", 41, 41, -41);
	printf("**%5d**%5.3d**%0d**%05.3d**\n", 6, 6, 6, 6);


	/* ��������
	* 
	 1f 1F 0x1f
     **41** 41**-41**
     **    6**  006**6**  006**
	
	*/

}

int stringf()
{
	printf("[%2s]\n", BLURB);
	printf("[%24s]\n", BLURB);
	printf("[%24.5s]\n", BLURB);  // .5��ʾֻ��ӡ5���ַ�
	printf("[%-24.5s]\n", BLURB);  // -��ʾ�ı���������


	/*s��������:
	   [Authentic imitation!]
       [    Authentic imitation!]
       [                   Authe]
       [Authe                   ]
	
	
	
	*/

}

int intconv()  //һЩ��ƥ�������ת��
{
	short num = PAGES1;
	short mnum = -PAGES1;

	printf(" num as short and unsigned short: %hd %hu\n", num, num);
	printf(" -num as short and unsigned short: %hd %hu\n", mnum, mnum);
	printf(" num as int and char: %d %c\n", num, num);
	printf(" WORDS as int, short, and char: %d %hd %c\n",WORDS,WORDS,WORDS);
	

	/* ��������:
	* 
	 num as short and unsigned short: 336 336
	 -num as short and unsigned short: -336 65200
	 num as int and char: 336 P  
	 WORDS as int, short, and char: 65618 82 R
	
	
	*/


}