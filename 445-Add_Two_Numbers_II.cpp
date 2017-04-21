class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool plus = false;
        int l, r;
        ListNode *head = NULL, *node;
        list<int> lhs, rhs;
        if ( l1 == NULL && l2 == NULL ) return NULL;
        while ( l1 != NULL ) {
            lhs.push_back(l1->val);
            l1 = l1->next;
        }
        while ( l2 != NULL ) {
            rhs.push_back(l2->val);
            l2 = l2->next;
        }

        auto lit = lhs.rbegin();
        auto rit = rhs.rbegin();
        while ( lit != lhs.rend() || rit != rhs.rend() || plus ) {
            l = 0, r = 0;
            if ( lit != lhs.rend() ) l = *lit++;
            if ( rit != rhs.rend() ) r = *rit++;
            l = l + r + int(plus);
            plus = l > 9;
            node = new ListNode(l%10);
            node->next = head;
            head = node;
        }
        return head == NULL ? new ListNode(0) : head;
    }
};
