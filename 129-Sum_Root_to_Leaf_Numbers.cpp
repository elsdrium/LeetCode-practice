class Solution {
    int foo(TreeNode* root, int num) {
        if ( root == NULL ) return 0;
        num = num*10 + root->val;
        if ( root->left == NULL && root->right == NULL ) return num;
        return foo(root->left, num) + foo(root->right, num);
    }
public:
    int sumNumbers(TreeNode* root) {
        return foo(root, 0);
    }
};
