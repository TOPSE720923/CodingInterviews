#include <iostream>
#include <exception>

using namespace std;

struct Node
{
	int _data;
	Node *_left;
	Node *_right;
	Node(int x)
		: _data(x)
		, _left(NULL)
		, _right(NULL)
	{}
};

void PreOrder(Node *root)
{
	if (root == NULL)
		return;
	cout << root->_data << " ";
	PreOrder(root->_left);
	PreOrder(root->_right);
}

void InOrder(Node *root)
{
	if (root == NULL)
		return;
	InOrder(root->_left);
	cout << root->_data << " ";
	InOrder(root->_right);
}

Node* _CBT(int* preStart, int* preEnd, int* inStart, int* inEnd)
{
	int rootValue = preStart[0];
	Node *root = new Node(rootValue);
	if (preStart == preEnd)
	{
		if (inStart == inEnd && *preStart == *inEnd)
			return root;
		else
		{
			cerr << "invalid input" << endl;
			exit(1);
		}
	}
	//find the pos between inStart and inEnd
	int *inRoot = inStart;
	while (inRoot <= inEnd && (*inRoot != rootValue))
		++inRoot;
	if (inRoot == inEnd && (*inRoot != rootValue))
	{
		cerr << "invalid input" << endl;
		exit(1);
	}
	
	int leftLen = inRoot - inStart;
	int rightLen = inEnd - inRoot;
	if (leftLen > 0)
		root->_left = _CBT(preStart + 1, preStart + leftLen, inStart, inStart + leftLen - 1);
	if (rightLen > 0)
		root->_right = _CBT(preStart + leftLen + 1, preEnd, inStart + leftLen + 1 , inEnd);
	return root;
}

Node *CreateBinaryTree(int *pre, int *in, int len)
{
	if (pre == NULL || in == NULL || len <= 0)
		return NULL;
	return _CBT(pre, pre + len - 1, in, in + len - 1);
}


//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
	cout << "Test1():" << endl;
	const int length = 8;
	int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	Node *root = CreateBinaryTree(preorder, inorder, length);
	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
}

//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
	cout << "Test2():" << endl;
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 5, 4, 3, 2, 1 };
	Node *root = CreateBinaryTree(preorder, inorder, length);
	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
}

//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
	cout << "Test3():" << endl;
	const int length = 5;
	int preorder[length] = { 1, 2, 3, 4, 5 };
	int inorder[length] = { 1, 2, 3, 4, 5 };
	Node *root = CreateBinaryTree(preorder, inorder, length);
	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
}

//       1
void Test4()
{
	cout << "Test4():" << endl;
	const int length = 1;
	int preorder[length] = { 1 };
	int inorder[length] = { 1 };
	Node *root = CreateBinaryTree(preorder, inorder, length);
	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
}

//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
	cout << "Test5():" << endl;
	const int length = 7;
	int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };
	Node *root = CreateBinaryTree(preorder, inorder, length);
	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
}

// NULL
void Test6()
{
	cout << "Test6():" << endl;
	Node *root = CreateBinaryTree(NULL, NULL, 0);
	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
}

// unmatched sequence
void Test7()
{
	cout << "Test7():" << endl;
	const int length = 4;
	int preorder[length] = { 1, 2, 4, 5};
	int inorder[length] = { 4, 2, 8, 1};
	Node *root = CreateBinaryTree(preorder, inorder, length);
	PreOrder(root);
	cout << endl;
	InOrder(root);
	cout << endl;
}



int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	return 0;
}
