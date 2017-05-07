class Solution {
    bool isIdentical(TreeNode* s, TreeNode* t) {
        if ( s == NULL && t == NULL ) return true;
        if ( s != NULL && t != NULL && s->val == t->val )
            return isIdentical(s->left, t->left) && isIdentical(s->right, t->right);
        return false;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if ( isIdentical(s, t) ) return true;
        if ( s == NULL ) return false;
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
