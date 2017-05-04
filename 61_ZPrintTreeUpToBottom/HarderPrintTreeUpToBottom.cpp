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

//层序遍历，奇数偶数变化
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
        bool shouldReverse = false;
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
                if (shouldReverse)
                {
                    reverse(v.begin(), v.end());
					shouldReverse = false;		                    
                }
                else
                {
                    shouldReverse = true;
                }
                
                ret.push_back(v);
                v.clear();

                toBePrinted = nextSize;
                nextSize = 0;
            }

        }
        return ret;
       	
    } 
};

//利用两个栈
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) 
    {
    	vector<vector<int>> ret;
            
        if (pRoot == NULL)
            return ret;
       	stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<int> v;
        
        s1.push(pRoot);
        
        while (!s1.empty() || !s2.empty())
        {
           if (!s1.empty())
           {
               while (!s1.empty())
               {
                   TreeNode* top = s1.top();
                   s1.pop();
                   v.push_back(top->val);
                   if (top->left != NULL)
                   {
                       s2.push(top->left);
                   }
                   if (top->right != NULL)
                   {
                       s2.push(top->right);
                   }
               }
               ret.push_back(v);
               v.clear();
           }
           else if (!s2.empty())
           {
               while (!s2.empty())
               {
                   TreeNode* top = s2.top();
                   s2.pop();
                   v.push_back(top->val);
                   if (top->right != NULL)
                   {
                       s1.push(top->right);
                   }
                   if (top->left != NULL)
                   {
                       s1.push(top->left);
                   }
               }
               ret.push_back(v);
               v.clear();
           }
        }
        return ret;
        
       	
    }
    
};