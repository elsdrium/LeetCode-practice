class Solution {
    ListNode* reverseKNodes(ListNode* head_prev, ListNode* prev, ListNode* curr, int k) {
        ListNode* temp;
        if ( k == 1 ) {
            temp = curr->next;
            curr->next = prev;
            head_prev->next = curr;
            return temp;
        }
        else {
            if ( curr->next == NULL )
                throw "No enough k nodes";
            temp = reverseKNodes(head_prev, curr, curr->next, k-1);
        }
        curr->next = prev;
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp;
        ListNode* ans = NULL;
        ListNode* head_prev = new ListNode(0);
        head_prev->next = head;
        
        while ( head != NULL ) {
            try {
                temp = reverseKNodes(head_prev, head_prev, head, k);
            }
            catch(...) {
                if ( ans == NULL )
                    return head;
                return ans;
            }
            
            if ( ans == NULL )
                ans = head_prev->next;
            head->next = temp;
            head_prev = head;
            head = temp;
        }
        return ans;
    }
};
