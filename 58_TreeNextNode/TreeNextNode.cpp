/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL)
            return NULL;
        
        TreeLinkNode* pNext = NULL;
        if (pNode->right != NULL) //���������գ�����������������
        {
            pNext = pNode->right;
            while (pNext->left != NULL)
            {
                pNext = pNext->left;
            }
            return pNext;
        }
        else //������Ϊ�գ���Ҫ������
        {
            pNext = pNode->next;
            
            while (pNext != NULL && pNext->right == pNode)
            {
                pNode = pNext;
                pNext = pNext->next;
            }
            
			return pNext;
        }
    }
};