class Solution {
public:
    int TreeDepth(TreeNode* root)
    {
    	if (root == NULL)
            return 0;
        int leftH = TreeDepth(root->left);
        int rightH = TreeDepth(root->right);
        
        return leftH>rightH ? leftH+1 : rightH+1;
    }
};
