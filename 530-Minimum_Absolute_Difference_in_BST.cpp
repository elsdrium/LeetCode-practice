class BSTIterator {
    list<pair<TreeNode*, bool>> tr;
public:
    BSTIterator(TreeNode *root) {
        while ( root != NULL ) {
            tr.push_back(make_pair(root, false));
            root = root->left;
        }
    }

    bool hasNext() {
        return tr.size();
    }

    int next() {
        TreeNode *curr = tr.back().first;
        bool right = tr.back().second;
        tr.pop_back();
        if ( right || curr->right == NULL ) {
            while ( tr.size() && tr.back().second ) {
                tr.pop_back();
            }
        }
        else {
            TreeNode *temp = curr->right;
            tr.push_back(make_pair(curr, true));
            do {
                tr.push_back(make_pair(temp, false));
                temp = temp->left;
            } while ( temp != NULL );
        }
        return curr->val;
    }
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        BSTIterator it(root);
        int min_diff, last, temp;
        temp = it.next();
        last = it.next();
        min_diff = last - temp;
        while ( it.hasNext() ) {
            temp = last;
            last = it.next();
            if ( last - temp < min_diff ) min_diff = last - temp;
        }
        return min_diff;
    }
};
