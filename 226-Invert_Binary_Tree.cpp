class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if ( root == NULL ) return NULL;
        TreeNode *node = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(node);
        return root;
    }
};
