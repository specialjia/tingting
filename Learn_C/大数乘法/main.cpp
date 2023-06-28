#include <iostream>
#include <string>

using namespace std;
string sum(string num1, string num2)
{
	string res{ "" };
	int length1 = num1.length() - 1; //方便取值
	int length2 = num2.length() - 1;
	int over = 0;   //进位
	while (length1 >= 0 || length2 >= 0)
	{
		int n1 = length1 >= 0 ? num1[length1] - '0' : 0;
		int n2 = length2 >= 0 ? num2[length2] - '0' : 0;
		int resTemp = n1 + n2 + over;
		over = resTemp / 10;
		int mode = resTemp % 10;
		res = to_string(mode) + res;
		length1--;
		length2--;

	}
	if (over)
	{
		res = to_string(over) + res;
	}
	return res;
}


struct ListNode 
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
	ListNode* head1 = l1;
	ListNode* head2 = l2;
	ListNode* res = new ListNode(0);
	ListNode* temp = res;
	int over = 0; //进位
	while (head1 || head2 )
	{
		int  n1 = head1 ?  head1->val : 0;
		head1 = head1 ? head1->next : nullptr;
		int  n2 = head2 ? head2->val : 0;
		head2 = head2 ? head2->next : nullptr;
		int sum = n1 + n2 + over;
		int mode = sum % 10;
		over = sum / 10;
		temp->next = new ListNode(mode);
		temp = temp->next;
	}
	if (over)
	{
		temp->next = new ListNode(over);
	}
	return res->next;
}
 

int numDecodings(string s) 
{
	int length = s.length();
	int pair = length / 2;

	for (int i = 0; i < pair; i++)
	{
		for (int j = 0; j < length-1; j++)
		{

		}
	}
	return 0;

}

int fact(int n)
{
	if (1 == n) return 1;
	return n * fact(n - 1);
}


int main()
{
	std::cout << fact(4);

}