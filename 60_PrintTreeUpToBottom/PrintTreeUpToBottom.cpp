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
        vector<vector<int> > Print(TreeNode* pRoot) 
        {
        	vector<vector<int>> ret;
            
            if (pRoot == NULL)
                return ret;
            queue<TreeNode*> q;
            q.push(pRoot);
            vector<int> v;
            int toBePrinted = 1;
            int nextSize = 0;
            
            while (!q.empty())
            {
                TreeNode* tmp = q.front();
                q.pop();
                
                if (tmp->left != NULL)
                {
                    q.push(tmp->left);
                    ++nextSize;
                }
                if (tmp->right != NULL)
                {
                    q.push(tmp->right);
                    ++nextSize;
                }
                
                v.push_back(tmp->val);
                --toBePrinted;
                
                if (toBePrinted == 0)
                {
                    ret.push_back(v);
                    v.clear();
                    
                    toBePrinted = nextSize;
                    nextSize = 0;
                }
                
            }
            return ret;
        }
    
};