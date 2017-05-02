/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot == NULL)
            return true;
		return isSymmetrical(pRoot->left, pRoot->right);
    }
    
    bool isSymmetrical(TreeNode* r1, TreeNode* r2)
    {
		if (r1 == NULL && r2 == NULL)
            return true;
        if (r1 == NULL || r2 == NULL)
            return false;
        if (r1->val != r2->val)
            return false;
        return isSymmetrical(r1->left, r2->right) && isSymmetrical(r1->right, r2->left);
        
    }

};