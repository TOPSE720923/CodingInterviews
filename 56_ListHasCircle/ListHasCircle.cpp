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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return NULL;
        
		ListNode* pFast = pHead;
        ListNode* pSlow = pHead;
        
        do
        {
            pSlow = pSlow->next;
            pFast = pFast->next->next;
            
        } while (pFast != pSlow);
        //快慢指针求相交点
    
    
    	ListNode* tmp = pHead;
        
        while (tmp != pSlow)
        {
            tmp = tmp->next;
            pSlow = pSlow->next;
        }
        
        return pSlow;
    }
};