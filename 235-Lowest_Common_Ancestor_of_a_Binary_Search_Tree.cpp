class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( p == q ) return p;
        while ( (root->val - p->val)*(root->val - q->val) > 0 ) {
            root = root->val - p->val > 0 ? root->left : root->right;
        }
        return root;
    }
};
