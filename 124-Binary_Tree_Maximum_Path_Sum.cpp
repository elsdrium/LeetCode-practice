class Solution {
    int result;
    int helper(TreeNode* root) {
        if ( root == NULL ) return 0;
        int lv = helper(root->left), rv = helper(root->right);
        if ( lv + root->val + rv > this->result )
            this->result = lv + root->val + rv;
        return max({0, lv + root->val, rv + root->val});
    }
public:
    int maxPathSum(TreeNode* root) {
        this->result = numeric_limits<int>::min();
        helper(root);
        return result;
    }
};
