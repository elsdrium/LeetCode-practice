class Solution {
    int getHeight(TreeNode* root, bool right) {
        if ( root == NULL ) return 0;
        int height = 1;
        if ( right )
            while ( root->right != NULL ) { root = root->right; ++height; }
        else
            while ( root->left != NULL ) { root = root->left; ++height; }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if ( root == NULL ) return 0;
        int lheight = getHeight(root, false), rheight = getHeight(root, true), h, result;
        if ( lheight == rheight ) return int(pow(2, rheight)) - 1;
        else {
            h = rheight;
            result = int(pow(2, h)) - 1;
            TreeNode *ln = root->left, *rn = root->right;
            while ( h-- ) {
                rheight = getHeight(ln, true);
                if ( rheight == --lheight ) {
                    result += int(pow(2, h));
                    if ( rn == NULL ) break;
                    ln = rn->left;
                    rn = rn->right;
                }
                else {
                    if ( ln == NULL ) break;
                    rn = ln->right;
                    ln = ln->left;
                }
            }
            return result;
        }
    }
};
