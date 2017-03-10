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


bool PrintLastKNode(Node *pHead, int k)
{
	assert(pHead != nullptr && k > 0);
	Node* pFast = pHead;
	Node* pSlow = pHead;
	for (int i = 0; i < k - 1; ++i)
	{
		if (pFast->m_next == nullptr)
		{
			cout << "the num of the node is less than " << k << endl;
			return false;
		}
		else
		{
			pFast = pFast->m_next;
		}
	}
	while (pFast->m_next != nullptr)
	{
		pSlow = pSlow->m_next;
		pFast = pFast->m_next;
	}
	cout << pSlow->m_data << endl;
	return true;
}


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

void TestCL()
{
	Node *pHead = CreateList(6);
	PrintLastKNode(pHead, 6);
	DestroyList(pHead);
}

//Node* FindMidNode(Node* pHead)
//{
//	Node* pFast = pHead;
//	Node* pSlow = pHead;
//	while (pFast != NULL && NULL != pFast->m_next) {
//		pFast = pFast->m_next->m_next;
//		pSlow = pSlow->m_next;
//	}
//	return pSlow;
//
//}

int main()
{
	TestCL();
	return 0;
}
