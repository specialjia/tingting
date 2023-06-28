// day54_ 动态构造存放学生信息的结构体数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<malloc.h>

struct Student
{
    int age;
    float score;
    char name[100];

};

int main()
{
    int len;
    struct Student * pArr;
    int i,j;
    struct Student t;

    // 动态的构造一维数组
    printf("请输入学生的个数: \n");
    printf("len = ");
    scanf("%d", & len);
    pArr = (struct Student *)malloc(len * sizeof(struct Student));

    for (i = 0; i < len; ++i)
    {
        printf("请输入第%d个学生的信息: \n", i + 1);
        printf("age = ");
        scanf("%d", &pArr[i].age);

        printf("name = ");
        scanf("%s", pArr[i].name); // name是数组名,本身就已经是数组首元素的地址,所以不能改成 &pArr[i].name

        printf("score = ");
        scanf("%f", &pArr[i].score);

    }

    // 按学生成绩升序排序  冒泡算法
    for (i = 0; i < len - 1 ; ++i)
    {
        for (j = 0; j < len - 1 - i; ++j)
        {
            if (pArr[j].score > pArr[j + 1].score) //>是升序  <是降序
            {
                t = pArr[j];
                pArr[j] = pArr[j + 1];
                pArr[j+1] = t;

            }

        }
    }


    printf("\n\n学生的信息是: \n");
    // 输出
    for (i = 0; i < len; ++i)
    {
        printf("第%d个学生的信息: \n", i + 1);
        printf("age = %d\n", pArr[i].age);
        printf("name = %s\n", pArr[i].name); 
        printf("score = %f", pArr[i].score);
       
        printf("\n");
    }
    free(pArr);
    pArr = NULL;
    return 0;
}

/* 动态构造存放学生信息的结构体数组:
*      动态构造一个数组 ,存放学生信息
*      然后分数排序输出
* 
* 

*/