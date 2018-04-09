class Solution {
    bool valid;
    pair<int, int> helper(TreeNode* node) {
        int low = node->val, high = node->val;
        pair<int, int> temp;
        if ( this->valid && node->left ) {
            if ( node->left->val >= node->val ) goto FEND;
            temp = helper(node->left);
            if ( temp.second >= node->val ) goto FEND;
            low = temp.first;
        }
        if ( this->valid && node->right ) {
            if ( node->right->val <= node->val ) goto FEND;
            temp = helper(node->right);
            if ( temp.first <= node->val ) goto FEND;
            high = temp.second;
        }
        return {low, high};

    FEND:
        this->valid = false;
        return temp;
    }
public:
    Solution() : valid(true) {}
    bool isValidBST(TreeNode* root) {
        if ( !root ) return true;
        helper(root);
        return this->valid;
    }
};
