struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		stack<TreeNode*> s;
		TreeNode* cur = pRootOfTree;
		TreeNode* prev = NULL;
		bool isFirst = true;
		while (cur != NULL || !s.empty())
		{
			while (cur != NULL)
			{
				s.push(cur);
				cur = cur->left;
			}

			TreeNode* top = s.top();
			s.pop();
			if (isFirst)
			{
				pRootOfTree = top;
				prev = top;
				isFirst = false;
			}
			else
			{
				top->left = prev;
				prev->right = top;
				prev = top;
			}
			if (top->right != NULL)
				cur = top->right;
		}
		return pRootOfTree;
	}

	TreeNode* ConvertRecursion(TreeNode* pRootOfTree)
	{
		if (pRootOfTree == NULL)
			return NULL;
		if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
			return pRootOfTree;
		TreeNode* left = ConvertRecursion(pRootOfTree->left); //left list
		TreeNode* leftEnd = left;
		while (leftEnd->right != NULL)
			leftEnd = leftEnd->right;
		if (leftEnd != NULL)
		{
			leftEnd->right = pRootOfTree;
			pRootOfTree->left = leftEnd;
		}	
		TreeNode* rightBeg = ConvertRecursion(pRootOfTree->right); //right list
		if (rightBeg != NULL)
		{
			rightBeg->left = pRootOfTree;
			pRootOfTree->right = rightBeg;
		}
		return left == NULL ? pRootOfTree : left;
	}
};

