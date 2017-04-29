class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2], temp;
        int diff = abs(result-target);
        sort(nums.begin(), nums.end());
        for ( int i=1, j, k; i!=nums.size(); ++i ) {
            j = i-1, k = i+1;
            while ( j >= 0 && k < nums.size() ) {
                temp = nums[i] + nums[j] + nums[k];
                if ( abs(temp-target) > diff ) {
                    temp-target>0 ? j-- : k++;
                    continue;
                }
                diff = abs(temp-target);
                result = temp;
                if ( j == 0 ) k++;
                else j--;
            }
        }
        return result;
    }
};
