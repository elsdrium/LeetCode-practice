class Solution {
    int target;
    vector<vector<int>> result;
    void generate_path(TreeNode *node, vector<int> path, int sum) {
        path.push_back(node->val);
        if ( node->left != NULL )
            generate_path(node->left, path, sum + node->val);
        if ( node->right != NULL )
            generate_path(node->right, path, sum + node->val);
        if ( node->left == NULL && node->right == NULL && sum + node->val == this->target )
            this->result.emplace_back(move(path));
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        this->target = sum;
        this->result = vector<vector<int>>();
        if ( root != NULL )
            generate_path(root, vector<int>(), 0);
        return result;
    }
};
