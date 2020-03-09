class Solution {
    ListNode* mergeKListsHelper(vector<ListNode*>::iterator start, vector<ListNode*>::iterator end) {
        int mid = (end - start) / 2;
        if ( mid < 1 ) return start == end ? NULL : *start;
        ListNode *left = mergeKListsHelper(start, start+mid),
                 *right = mergeKListsHelper(start+mid, end);
        return merge(left, right);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if ( l1 == NULL ) return l2;
        if ( l2 == NULL ) return l1;
        ListNode *head, *cur;
        if ( l1->val < l2->val ) {
            head = l1;
            l1 = l1->next;
        }
        else {
            head = l2;
            l2 = l2->next;
        }
        for ( cur = head; l1 != NULL && l2 != NULL; cur = cur->next) {
            if ( l1->val < l2->val ) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
        }
        cur->next = (l1 == NULL ? l2 : l1);
        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsHelper(lists.begin(), lists.end());
    }
};

static const auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
