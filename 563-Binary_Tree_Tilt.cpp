class Solution {
    int sumTree(TreeNode* node) {
        if ( node == NULL ) return 0;
        return node->val + sumTree(node->left) + sumTree(node->right);
    }
public:
    int findTilt(TreeNode* root) {
        if ( root == NULL ) return 0;
        return findTilt(root->left) + findTilt(root->right) + abs(sumTree(root->left) - sumTree(root->right));
    }
};
