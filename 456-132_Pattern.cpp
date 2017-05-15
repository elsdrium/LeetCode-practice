class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int high = numeric_limits<int>::min();
        vector<int> stack;
        for ( int i=nums.size()-1; i>=0; --i ) {
            if ( nums[i] < high ) return true;
            else {
                while ( stack.size() && stack.back() < nums[i] ) {
                    high = stack.back();
                    stack.pop_back();
                }
                stack.push_back(nums[i]);
            }
        }
        return false;
    }
};
