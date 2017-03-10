#include <iostream>
#include <assert.h>
using namespace std;

typedef struct ListNode
{
	int m_data;
	ListNode* m_next;
	ListNode()
		: m_data(0)
		, m_next(nullptr)
	{}

	ListNode(int x)
		: m_data(x)
		, m_next(nullptr)
	{}
}Node;



void PushBack(Node* &pHead, int x)
{
	if (pHead == nullptr)
	{
		pHead = new Node(x);
		return;
	}
	Node* last = pHead;
	while (last->m_next != nullptr)
	{
		last = last->m_next;
	}
	last->m_next = new Node(x);
}


void DestroyList(Node* pHead)
{
	if (pHead == nullptr)
		return;
	Node* del = pHead;
	while (pHead)
	{
		pHead = pHead->m_next;
		delete del;
		del = pHead;
	}
}

void PrintList(Node* pHead)
{
	while (pHead != nullptr)
	{
		cout << pHead->m_data << " ";
		pHead = pHead->m_next;
	}
	cout << endl;
}

Node* MergeSortedList(Node* pHead1, Node* pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;
	else if (pHead2 == nullptr)
		return pHead1;
	Node* newHead = nullptr;
	if (pHead1->m_data < pHead2->m_data)
	{
		newHead = pHead1;
		pHead1 = pHead1->m_next;
	}
	else
	{
		newHead = pHead2;
		pHead2 = pHead2->m_next;
	}
	Node* cur = newHead;
	while (pHead1 != nullptr && pHead2 != nullptr)
	{
		if (pHead1->m_data < pHead2->m_data)
		{
			cur->m_next = pHead1;
			cur = cur->m_next;
			pHead1 = pHead1->m_next;
		}
		else
		{
			cur->m_next = pHead2;
			cur = cur->m_next;
			pHead2 = pHead2->m_next;
		}
	}
	while (pHead1 != nullptr)
	{
		cur->m_next = pHead1;
		cur = cur->m_next;
		pHead1 = pHead1->m_next;
	}
	while (pHead2 != nullptr)
	{
		cur->m_next = pHead2;
		cur = cur->m_next;
		pHead2 = pHead2->m_next;
	}
	return newHead;
}


Node* MergeSortedListRecursion(Node* pHead1, Node* pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;
	else if (pHead2 == nullptr)
		return pHead1;
	Node* newHead = nullptr;
	if (pHead1->m_data < pHead2->m_data)
	{
		newHead = pHead1;
		newHead->m_next = MergeSortedListRecursion(pHead1->m_next, pHead2);
	}
	else
	{
		newHead = pHead2;
		newHead->m_next = MergeSortedListRecursion(pHead1, pHead2->m_next);
	}
	return newHead;
}

void Test()
{
	Node *pHead1 = nullptr;
	PushBack(pHead1, 1);
	PushBack(pHead1, 2);
	PushBack(pHead1, 5);
	PushBack(pHead1, 7);
	
	Node *pHead2 = nullptr;
	PushBack(pHead2, 2);
	PushBack(pHead2, 3);
	PushBack(pHead2, 4);
	PushBack(pHead2, 76);

	//Node* newHead = MergeSortedList(pHead1, pHead2);
	Node* newHead = MergeSortedListRecursion(pHead1, pHead2);

	PrintList(newHead);
}



int main()
{
	Test();
	return 0;
}
