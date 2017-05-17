class Solution {
    void inorderHelper(vector<int>& v, TreeNode* root) {
        if ( root == NULL ) return;
        inorderHelper(v, root->left);
        v.push_back(root->val);
        inorderHelper(v, root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(result, root);
        return result;
    }
};
