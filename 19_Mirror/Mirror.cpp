#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


typedef struct TreeNode
{
	int m_data;
	TreeNode* m_left;
	TreeNode* m_right;
	TreeNode(int x)
		: m_data(x)
		, m_left(nullptr)
		, m_right(nullptr)
	{}
}Node;


//Node* CreateTree(int* a ,int n, int& index)
//{
//	Node* root = nullptr;
//	if (index < n && a[index] != '#')
//	{
//		root = new Node(a[index]);
//		root->m_left = CreateTree(a, n, ++index);
//		root->m_right = CreateTree(a, n, ++index);
//	}
//	return root;
//}
//
//void CreateTree(Node* &root, int* a, int n, int& index)
//{
//	if (index < n && a[index] != '#')
//	{
//		root = new Node(a[index]);
//		CreateTree(root->m_left, a, n, ++index);
//		CreateTree(root->m_right, a, n, ++index);
//	}
//}

void MirrorRecursion(Node* root)
{
	if (root == nullptr)
		return;
	if (root->m_left == nullptr && root->m_right == nullptr)
		return;
	Node* temp = root->m_left;
	root->m_left = root->m_right;
	root->m_right = temp;
	if (root->m_left != nullptr)
		MirrorRecursion(root->m_left);
	if (root->m_right != nullptr)
		MirrorRecursion(root->m_right);
}

//like BFS
void MirrorQueue(Node *root)
{
	if (root == nullptr)
		return;
	queue<Node*> q;
	q.push(root);
	
	while (!q.empty())
	{
		Node* front = q.front();
		q.pop();
		Node* temp = front->m_left;
		front->m_left = front->m_right;
		front->m_right = temp;

		if (front->m_left != nullptr)
			q.push(front->m_left);
		if (front->m_right != nullptr)
			q.push(front->m_right);	
	}
}

//like DFS
void MirrorStack(Node *root)
{
	if (root == nullptr)
		return;
	stack<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* front = q.top();
		q.pop();
		Node* temp = front->m_left;
		front->m_left = front->m_right;
		front->m_right = temp;

		if (front->m_left != nullptr)
			q.push(front->m_left);
		if (front->m_right != nullptr)
			q.push(front->m_right);
	}
}

int main()
{

	return 0;
}
