#include <iostream>
#include <queue>

using namespace std; 

typedef struct BinaryTreeNode //define the BinaryTreeNode
{
	int _data;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;
	BinaryTreeNode(int x)
		:_data(x)
		, _left(nullptr)
		, _right(nullptr)
	{}
}Node;


//use the queue to BFS  
void LevelOrder(Node* root)
{
	queue<Node*> q;
	if (root != nullptr)
		q.push(root);
	while (!q.empty())
	{
		Node *temp = q.front();
		cout << temp->_data << " ";
		q.pop();
		if (temp->_left != nullptr)
			q.push(temp->_left);
		if (temp->_right != nullptr)
			q.push(temp->_right);
	}
	cout << endl;
}



int main()
{
	return 0;
}
