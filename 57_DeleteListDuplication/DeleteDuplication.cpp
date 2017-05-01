/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        
		ListNode* first = new ListNode(0);
        first->next = pHead;
        
        ListNode* prev = first;
        ListNode* cur = pHead;
        ListNode* next = cur->next;
        
        while (next != NULL)
        {
            if (cur->val != next->val)
            {
                prev = cur;
                cur = next;
                next = next->next;
            }
            else //��ͬ
            {
                while (next != NULL && next->val == cur->val)
                {
                    next = next->next;
                }
                //ɾ����ͬ�Ľ��
                
                while (cur != next)
                {
                    ListNode* del = cur;
					cur = cur->next;
                    delete del;
                    del = NULL;
                }
                
                //����
                prev->next = cur;
                if (next != NULL)
                	next = next->next;
            }
        }
  		return first->next;      
    }
};