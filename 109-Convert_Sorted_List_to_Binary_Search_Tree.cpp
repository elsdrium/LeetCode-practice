class Solution {
    TreeNode* vector2BST(const vector<int>& v, int start, int end) {
        if ( start == end ) return NULL;
        int rindex = (start+end)/2;
        TreeNode *root = new TreeNode(v[rindex]);
        root->left = vector2BST(v, start, rindex);
        root->right = vector2BST(v, rindex+1, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *lnode = head;
        vector<int> v;
        while ( lnode != NULL ) {
            v.push_back(lnode->val);
            lnode = lnode->next;
        }
        return vector2BST(v, 0, v.size());
    }
};
