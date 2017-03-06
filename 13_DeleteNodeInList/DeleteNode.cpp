struct Node
{
	int m_value;
	Node* m_next;
	Node(int x)
		: m_value(x)
		, m_next(nullptr)
	{}

	Node()
		: m_value(0)
		, m_next(nullptr)
	{}
};


void DeleteNode(Node* &pHead, Node *toBeDeleted)
{
	if (pHead == nullptr || toBeDeleted == nullptr)
	{
		return;
	}
	// ths list has only one node
	if (toBeDeleted == pHead)
	{
		delete pHead;
		toBeDeleted = nullptr;
		pHead = nullptr;
	}
	Node* nextNode = toBeDeleted->m_next;
	//we wanna delete the last node
	if (nextNode == nullptr)
	{
		Node *cur = pHead;
		while (cur->m_next != toBeDeleted)
		{
			cur = cur->m_next;
		}
		cur->m_next = nullptr;
		delete toBeDeleted;
		toBeDeleted = nullptr;
	}
	else//not the last node
	{
		toBeDeleted->m_value = nextNode->m_value;
		toBeDeleted->m_next = nextNode->m_next;
		delete nextNode;
		nextNode = nullptr;
	}
}

