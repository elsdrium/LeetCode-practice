class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *prev = head, *first = head, *second = head == NULL ? NULL : head->next;
        if ( first == NULL || second == NULL ) return head;
        else {
            first->next = second->next;
            second->next = first;
            head = second;
            first = first->next;
            second = first == NULL ? NULL : first->next;
        }
        while ( first != NULL && second != NULL ) {
            first->next = second->next;
            second->next = first;
            prev->next = second;
            prev = first;
            first = first->next;
            second = first == NULL ? NULL : first->next;
        }
        return head;
    }
};
