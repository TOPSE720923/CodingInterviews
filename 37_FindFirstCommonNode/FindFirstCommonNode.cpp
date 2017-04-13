/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (pHead1 == NULL || pHead2 == NULL)
            return NULL;
        
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        int count1 = 0;
        int count2 = 0;
        while (p1 != NULL)
        {
            ++count1;
            p1 = p1->next;
        }     
       
        while (p2 != NULL)
        {
            ++count2;
            p2 = p2->next;
        }
        
        if (count1 >= count2)
        {
            int n = count1 - count2;
            p1 = pHead1;
            p2 = pHead2;
            while (n--)
            {
                p1 = p1->next;
            }
        }
        else
        {
            int n = count2 - count1;
            p1 = pHead1;
            p2 = pHead2;
            while (n--)
            {
                p2 = p2->next;
            }
        }
        
        while (p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};
