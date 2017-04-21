class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> uset;
        while ( head != NULL ) {
            if ( uset.find(head) != uset.end() ) return head;
            uset.insert(head);
            head = head->next;
        }
        return NULL;
    }
};
