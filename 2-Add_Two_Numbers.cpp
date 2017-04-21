class Solution {
    ListNode* reverseAddNode(ListNode* l1, ListNode* l2, bool one) {
        int l1_val, l2_val;
        ListNode *l1_next, *l2_next;
        if ( l1 == NULL )
            if ( l2 == NULL )
                if ( one )
                    return new ListNode(1);
                else
                    return NULL;
            else {
                l1_val = 0;
                l2_val = l2->val;
                l1_next = NULL;
                l2_next = l2->next;
            }
        else if ( l2 == NULL ) {
            l1_val = l1->val;
            l2_val = 0;
            l1_next = l1->next;
            l2_next = NULL;
        }
        else {
            l1_val = l1->val;
            l2_val = l2->val;
            l1_next = l1->next;
            l2_next = l2->next;
        }
            
        int sum = l1_val + l2_val + int(one);
        int val = sum % 10;
        ListNode *result = new ListNode(val);
        result->next = reverseAddNode(l1_next, l2_next, sum!=val);
        return result;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return reverseAddNode(l1, l2, false);
    }
};
