class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        if ( findNums.empty() ) return findNums;
        vector<int> stk(1, nums.front());
        unordered_map<int, int> nge;
        for ( int j=1; j!=nums.size(); ++j ) {
            while ( stk.size() && nums[j] > stk.back() ) {
                nge[stk.back()] = nums[j];
                stk.pop_back();
            }
            stk.push_back(nums[j]);
        }
        while ( stk.size() ) {
            nge[stk.back()] = -1;
            stk.pop_back();
        }
        for ( int i=0; i!=findNums.size(); ++i )
            findNums[i] = nge[findNums[i]];
        return findNums;
    }
};
