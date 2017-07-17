class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        if ( root == NULL ) return result;
        vector<TreeNode *> frontier = {root};
        while ( frontier.size() ) {
            long long vsum = 0;
            vector<TreeNode *> temp; temp.reserve(frontier.size()<<1);
            for ( TreeNode *tn : frontier ) {
                vsum += tn->val;
                if ( tn->left != NULL ) temp.push_back(tn->left);
                if ( tn->right != NULL ) temp.push_back(tn->right);
            }
            result.push_back(static_cast<double>(vsum) / frontier.size());
            frontier.swap(temp);
        }
        return result;
    }
};
