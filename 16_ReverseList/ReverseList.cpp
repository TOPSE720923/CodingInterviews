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


Node* CreateList(int num)
{
	Node* pHead = new Node(1);
	Node* cur = pHead;
	int i = 2;
	while (--num)
	{
		Node* temp = new Node(i++);
		cur->m_next = temp;
		cur = temp;
	}
	return pHead;
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

Node* ReverseList(Node* pHead)
{
	if (pHead == nullptr || pHead->m_next == nullptr)
		return pHead;
	Node* prev = nullptr;
	Node* cur = pHead;
	Node* next = cur->m_next;
	while (next != nullptr)
	{
		cur->m_next = prev;
		prev = cur;
		cur = next;
		next = next->m_next;
	}
	cur->m_next = prev;
	return cur;
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

//pair<phead last>
pair<Node*, Node*> ReverseListRecursion(Node* pHead)
{
	if (pHead == nullptr || pHead->m_next == nullptr)
		return make_pair(pHead, pHead);
	pair<Node*, Node*> node = ReverseListRecursion(pHead->m_next);
	Node* last = node.second;
	last->m_next = pHead;
	pHead->m_next = nullptr;
	return make_pair(node.first, pHead);
}

Node* ReverseListRecursion2(Node* pHead)
{
	if (pHead == nullptr || pHead->m_next == nullptr)
		return pHead;
	Node* last = pHead->m_next;
	Node* newHead = ReverseListRecursion2(last);
	last->m_next = pHead;
	pHead->m_next = nullptr;
	return newHead;
}


void Test()
{
	Node *pHead = CreateList(6);
	/*PrintLastKNode(pHead, 6);*/
	/*pHead = ReverseList(pHead);*/
	//Node* pHead = nullptr;
	PrintList(pHead);
	//pair<Node*, Node*> head = ReverseListRecursion(pHead);
	//pHead = head.first;

	pHead = ReverseListRecursion2(pHead);
	PrintList(pHead);
	DestroyList(pHead);
}



int main()
{
	Test();
	return 0;
}
