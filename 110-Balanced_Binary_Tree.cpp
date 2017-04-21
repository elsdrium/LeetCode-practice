class Solution {
    int checkHeight(TreeNode* node) {
        if ( node == NULL ) return 0;
        int lheight = checkHeight(node->left);
        if ( lheight == -1 ) return -1;
        int rheight = checkHeight(node->right);
        if ( rheight == -1 ) return -1;
        
        if ( lheight == rheight || lheight+1 == rheight || lheight == rheight+1 )
            return max(lheight, rheight)+1;
            
        return -1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
