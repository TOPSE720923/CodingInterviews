class Solution {
public:
    bool IsBalanced_Solution(TreeNode* root) {
        int height = 0;
        return __isBalancedTree(root, height);
    }
    
    bool __isBalancedTree(TreeNode* root, int& height)
    {
		if (root == NULL)
        {
            return true;
        }
        
        int leftH = 0;
        if (!__isBalancedTree(root->left, leftH))
            return false;
        
        int rightH = 0;
        if (!__isBalancedTree(root->right, rightH))
    		return false;
        
        height = max(leftH, rightH) + 1;
        if (abs(leftH - rightH) <= 1)
            return true;
		else
            return false;
    }
};
