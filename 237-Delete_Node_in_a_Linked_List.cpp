class Solution {
public:
    void deleteNode(ListNode* node) {
        int val;
        while ( node->next != NULL ) {
            node->val = node->next->val;
            if( node->next->next == NULL ) break;
            node = node->next;
        }
        node->next = NULL;
    }
};
