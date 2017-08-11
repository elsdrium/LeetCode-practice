class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if ( nums.empty() ) return vector<int>();
        deque<int> dq;
        vector<int> result(nums.size()-k+1);
        for ( int i = 0; i < nums.size(); ++i ) {
            while ( dq.size() && nums[i] > nums[dq.back()] ) dq.pop_back();
            dq.push_back(i);
            if ( dq.front() + k == i ) dq.pop_front();
            if ( i >= k - 1 ) result[i-k+1] = nums[dq.front()];
        }
        return result;
    }
};
