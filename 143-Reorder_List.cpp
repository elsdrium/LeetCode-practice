class Solution {
public:
    void reorderList(ListNode* head) {
        if ( head == NULL ) return;
        deque<ListNode *> dq;
        ListNode *ln = head;
        while ( head != NULL ) {
            dq.push_back(head);
            head = head->next;
        }
        dq.pop_front();
        while ( dq.size() ) {
            ln->next = dq.back();
            dq.pop_back();
            ln = ln->next;
            if ( dq.size() ) {
                ln->next = dq.front();
                dq.pop_front();
                ln = ln->next;
            }
        }
        ln->next = NULL;
    }
};
