class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nge(nums.size());
        if ( nums.empty() ) return nge;
        list<int> stack;
        int start = max_element(nums.begin(), nums.end()) - nums.begin();
        nge[start] = -1;
        stack.push_back(nums[start]);
        for ( int i=start-1; i!=start; i=(!i?nums.size()-1:i-1) ) {
            if ( i < 0 ) i += nums.size();
            while ( stack.size() && nums[i] >= stack.back() ) stack.pop_back();
            nge[i] = stack.empty() ? -1 : stack.back();
            stack.push_back(nums[i]);
        }
        return nge;
    }
};
