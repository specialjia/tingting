//day59_链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
struct Node
{
    int data;//数据域
    struct Node * pNext;//指针域

};
  
//函数声明
Node* create_list(void);
void traverse_list(struct Node *);

int main()
{
    struct Node* pHead = NULL;
    pHead = create_list();// 功能是创建一个非循环单链表
    traverse_list(pHead);


    return 0;
}

struct Node* create_list()
{
    int len; // 用来存放有效节点的个数
    int i;
    int val;// 用来临时存放用户输入的结点的值
    // 分配了一个不存放有效数据的头结点
    struct Node* pHead = (struct Node*)malloc(sizeof(struct Node));
    if (NULL == pHead)
    {
        printf("分配失败,程序终止!\n");
        exit(-1);
    }
    struct Node* pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入您需要生成的链表节点的个数: len = ");
        scanf("%d",&len);
}








/*
//定义一个链表节点的数据类型
struct Node
{
    int data;
    struct Node* pNext;
};
Node* CreateList();
void TraverseList(Node* pHead);

int main()
{
    struct Node* pHead;
    pHead = CreateList();  // pHead用来存放链表结点的地址
    TraverseList(pHead);


    return 0;
}
Node* CreateList()
{
    Node* element = (Node*)malloc(sizeof(Node));
    if (NULL == element)
    {
        printf("malloc failed!");
    }
    element->data = 0;
    element->pNext = NULL;


    return element;
}
void TraverseList(Node* pHead)
{
    printf("node 1,data:%d\n", pHead->data);
    printf("node 1,pNext:%p\n", pHead->pNext);
}
*/

/*链表
*   算法:解题的方法和步骤
*      狭义定义: 对存储数据的操作
*      广义定义:广义的算法也叫泛型  无论数据是如何存储的,对该数据的操作都是一样的
* 
*   我们至少可以通过两种结构来存储数据
*       数组: 存储数据快  需要一个连续的很大的内存  插入和删除元素的效率很低
*       链表: 插入和删除元素效率高 不需要一个连续的很大的内存  查找某个位置的元素效率低
* 
           头结点:头结点的数据类型与首节点的类型一致,是首节点前面的那个节点 头结并不存放有效数据 设置其目的是为了方便对链表操作
           头指针:存放头结点地址的指针变量
           首节点: 存放第一个有效数据的节点
           尾节点: 存放最后一个有效数据的节点





*/