#include <iostream>
#include <cstdio>
#include <assert.h>
using namespace std;


typedef struct TreeNode
{
	int m_data;
	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode()
		: m_data(0)
		, m_left(nullptr)
		, m_right(nullptr)
	{}

	TreeNode(int x)
		: m_data(x)
		, m_left(nullptr)
		, m_right(nullptr)
	{}
}Node;


bool DoesLargeHaveSmall(Node* largeTree, Node* smallTree)
{
	if (smallTree == nullptr)
		return true;
	if (largeTree == nullptr)
		return false;
	if (largeTree->m_data != smallTree->m_data)
		return false;
	return DoesLargeHaveSmall(largeTree->m_left, smallTree->m_left) && DoesLargeHaveSmall(largeTree->m_right, smallTree->m_right);
}

//check whether smallRoot is the subTree of the largeRoot
bool HasSubTree(Node* largeRoot, Node* smallRoot)
{
	bool ret = false;
	if (largeRoot != nullptr && smallRoot != nullptr)
	{
		if (largeRoot->m_data == smallRoot->m_data)
			ret = DoesLargeHaveSmall(largeRoot, smallRoot);
		if (!ret)
			ret = HasSubTree(largeRoot->m_left, smallRoot);
		if (!ret)
			ret = HasSubTree(largeRoot->m_right, smallRoot);
	}
	return ret;
}

//check whether the two trees are the same
bool IsSameTree(Node* root1, Node* root2)
{
	if (root1 == nullptr && root2 == nullptr)
		return true;
	else if (root1 != nullptr && root2 == nullptr || root1 == nullptr && root2 != nullptr)
		return false;
	if (root1->m_data != root2->m_data)
		return false;
	return IsSameTree(root1->m_left, root2->m_left) && IsSameTree(root1->m_right, root2->m_right);
}

//check whether the two trees are isomorphic
//bool Isomorphic(Node* root1, Node* root2)
//{
//	if (root1 == nullptr && root2 == nullptr)
//		return true;
//	else if (root1 != nullptr && root2 == nullptr || root1 == nullptr && root2 != nullptr)
//		return false;
//	if (root1->m_data != root2->m_data)
//		return false;
//	return IsSameTree(root1->m_left, root2->m_left) && IsSameTree(root1->m_right, root2->m_right)
//		|| IsSameTree(root1->m_right, root2->m_left) && IsSameTree(root1->m_left, root2->m_right);
//}

Node* CreateTree(int *a, int n, int& index)
{
	assert(a != nullptr && n > 0);
	Node* root = nullptr;
	if (index < n && a[index] != '#')
	{
		root = new Node(a[index]);
		root->m_left = CreateTree(a, n, ++index);
		root->m_right = CreateTree(a, n, ++index);
	}
	return root;
}

void PreOrder(Node* root)
{
	if (root == nullptr)
		return;
	cout << root->m_data << " ";
	PreOrder(root->m_left);
	PreOrder(root->m_right);
}


void Test()
{
	int a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	int n = sizeof(a) / sizeof(a[0]);
	int index = 0;
	Node* largeRoot = CreateTree(a, n, index);

	int b[] = { 2, 3, '#', '#',4, };
	int n2 = sizeof(b) / sizeof(b[0]);
	int i = 0;
	Node* smallRoot = CreateTree(b, n2, i);

	cout << HasSubTree(largeRoot, smallRoot) << endl;
	//cout << IsSameTree(largeRoot, smallRoot) << endl;
	//cout << Isomorphic(largeRoot, smallRoot) << endl;
}

int main()
{
	Test();
}
