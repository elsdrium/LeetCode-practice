class Solution {
    TreeNode* helper(vector<int>& nums, int index, int size) {
        if ( !size ) return NULL;
        int mid = index + size/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, index, mid - index);
        root->right = helper(nums, mid + 1, (size-1) / 2);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};
