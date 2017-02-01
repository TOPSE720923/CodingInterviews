#include <iostream>
#include <stack>

using namespace std;

struct Node //define the ListNode
{
	int _value;
	Node *_next;	
	Node(int x)
		: _value(x)
		, _next(NULL)
	{}
};


void PushBack(Node *& pHead, int x)//push back the node in the list
{
	if (pHead == NULL) 
	{
		pHead = new Node(x);
		return;
	}	
	else
	{
		Node *cur = pHead;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = new Node(x);
	}	
}


void PrintReversinglyWithStack(Node *cur)//use the stack to print the list in the reversed order
{
	stack<Node *> stk;
	while (cur)
	{
		stk.push(cur);
		cur = cur->_next;
	}
	
	while (!stk.empty())
	{
		Node *cur = stk.top();
		cout << cur->_value << " ";
		stk.pop();
	}
	cout << endl;
}

void PrintReversinglyWithRecursion(Node *cur)//use the recursion to print the list in the reversed order
{
	if (cur == NULL)
		return;
	PrintReversinglyWithRecursion(cur->_next);
	cout << cur->_value << " " ;
}

void Print(Node *pHead)//print the list
{
	while (pHead)
	{
		printf("%d ", pHead->_value);
		pHead = pHead->_next;	
	}	
	cout << endl;
} 


void ReverseList(Node **pHead)//reverse the list with the double-pointer argument
{
	if (*pHead == NULL || (*pHead)->_next == NULL)
		return;
	Node *prev = NULL;
	Node *cur = *pHead;
	Node *next = cur->_next;
	while (next != NULL)
	{
		cur->_next = prev;
		prev = cur;
		cur = next;
		next = next->_next;
	}
	cur->_next = prev;
	*pHead = cur;
}

void RList(Node *&pHead)//reverse the list with the reference argument
{
	if (pHead == NULL || pHead->_next == NULL)
		return; 
	Node *prev = NULL;
	Node *cur = pHead;
	Node *next = cur->_next;
	while (next != NULL)
	{
		cur->_next = prev;
		prev = cur;
		cur = next;
		next = next->_next;
	}
	cur->_next = prev;
	pHead = cur;
}

void Test()
{
	Node *pHead = NULL;
	PushBack(pHead, 1);
//	PushBack(pHead, 2);
//	PushBack(pHead, 3);
//	PushBack(pHead, 4);
//	PushBack(pHead, 5);
//	PushBack(pHead, 6);
//	PushBack(pHead, 7);
	Print(pHead);
	PrintReversinglyWithRecursion(pHead); 
	cout << endl;
	PrintReversinglyWithStack(pHead);
		
	ReverseList(&pHead);
	Print(pHead);
	RList(pHead);
	Print(pHead);
}



int main()
{ 
	Test();
	return 0;
}
