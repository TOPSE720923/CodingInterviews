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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == NULL || k <= 0)
            return NULL;
        vector<TreeNode*> v;
        InOrder(pRoot, v);
        int size = v.size();
        if (size < k)
            return NULL;    
        return v[k-1];
    }
    
    void InOrder(TreeNode* root, vector<TreeNode*>& v)
    {
        if (root == NULL)
            return;
        InOrder(root->left, v);
       	v.push_back(root);
        InOrder(root->right, v);
    }   
};


class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (pRoot == NULL || k <= 0)
            return NULL;
        int t = k;
 		return InOrder(pRoot, t);
    }
    
    //�����������������Ϊ��������
    TreeNode* InOrder(TreeNode* root, int& k)
    {
        TreeNode* ret = NULL;
       	
        if (root->left != NULL)
        	ret = InOrder(root->left, k);
      	
        //���������û�ҵ�������ǰ�����
        if (ret == NULL)
        {
            k--;
        	if (k == 0)
            	ret = root; 
        }
      
        //��������͸���û�ҵ����͵�����������
        if (ret == NULL && root->right != NULL)
        	ret = InOrder(root->right, k);
        return ret;
    }  
};