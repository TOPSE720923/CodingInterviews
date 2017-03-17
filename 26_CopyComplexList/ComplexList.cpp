#include <iostream>
#include <cstdio>

#include <unordered_map>
using namespace std;



struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x)
		: label(x), next(NULL), random(NULL)
	{}
};


RandomListNode* CreateList(int times)
{
	RandomListNode* pHead = new RandomListNode(1);
	RandomListNode* cur = pHead;
	int i = 2;
	while (i <= 6)
	{
		RandomListNode* temp = new RandomListNode(i);
		cur->next = temp;
		cur = cur->next;
		++i;
	}

	return pHead;
}

void PrintList(RandomListNode* pHead)
{
	while (pHead != NULL)
	{
		cout << pHead->label << " ";
		pHead = pHead->next;
	}
	cout << endl;
}


RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	RandomListNode* cur = pHead;
	//copy each node and insert the node
	while (cur != NULL)
	{
		RandomListNode* temp = new RandomListNode(cur->label);
		temp->next = cur->next;
		cur->next = temp;

		cur = temp->next;
	}
	//set the random pointer
	cur = pHead;
	while (cur != NULL)
	{
		RandomListNode* pClone = cur->next;
		if (cur->random != NULL)
		{
			pClone->random = cur->random->next;
		}
		cur = pClone->next;
	}

	//split the list
	RandomListNode* newHead = pHead->next;
	RandomListNode* prev = pHead;
	cur = newHead;
	while (prev != NULL)
	{
		prev->next = cur->next;
		prev = prev->next;
		if (prev != NULL)
		{
			cur->next = prev->next;
			cur = cur->next;
		}
	}
	return newHead;
}


RandomListNode* CloneWithHash(RandomListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	unordered_map<RandomListNode*, RandomListNode*> nodes;

	RandomListNode* newHead = new RandomListNode(pHead->label);
	RandomListNode* newCur = newHead;

	nodes.insert(make_pair(pHead, newHead));

	RandomListNode* cur = pHead->next;
	while (cur != nullptr)
	{
		RandomListNode* temp = new RandomListNode(cur->label);
		nodes.insert(make_pair(cur, temp));

		newCur->next = temp;
		newCur = temp;

		cur = cur->next;
	}
	//deal with random
	unordered_map<RandomListNode*, RandomListNode*>::iterator it = nodes.begin();
	while (it != nodes.end())
	{
		if (it->first->random != nullptr)
			it->second->random = nodes[it->first->random];
		++it;
	}

	return newHead;
}




int main()
{
	RandomListNode* head = CreateList(6);
	RandomListNode* newHead = CloneWithHash(head);
	PrintList(head);





	return 0;
}
