class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> uset;
        while ( head != NULL ) {
            if ( uset.find(head) != uset.end() ) return true;
            uset.insert(head);
            head = head->next;
        }
        return false;
    }
};
