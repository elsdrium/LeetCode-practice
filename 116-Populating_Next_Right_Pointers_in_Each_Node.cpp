/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if ( root == NULL ) return;
        TreeLinkNode *next = root;
        while ( next->left != NULL && next->right != NULL ) {
            next->left->next = next->right;
            if ( next->next == NULL ) break;
            else {
                next->right->next = next->next->left;
                next = next->next;
            }
        }
        connect(root->left);
    }
};

static const auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
};
