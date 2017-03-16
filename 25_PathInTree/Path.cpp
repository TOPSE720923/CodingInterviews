#include <iostream>
//#include <cstdio>
//#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) 
		: val(x)
		, left(NULL)
		, right(NULL) {}
};


void FindPath(TreeNode* root, int expectNumber, vector<TreeNode*>& v, int curSum)
{
	if (root == NULL)
		return;
	v.push_back(root);
	curSum += root->val;
	if (root->left == NULL && root->right == NULL && curSum == expectNumber)
	{
		for (int i = 0; i < (int)v.size(); ++i)
		{
			cout << v[i]->val << " ";
		}
		cout << endl;
	}
	FindPath(root->left, expectNumber, v, curSum);
	FindPath(root->right, expectNumber, v, curSum);
	v.pop_back();
}


void FindPath(TreeNode* root, int expectNumber) 
{
	if (root == NULL)
		return;
	vector<TreeNode*> v;
	int curSum = 0;
	FindPath(root, expectNumber, v, curSum);
}



int main()
{


	return 0;
}

