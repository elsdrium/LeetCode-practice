class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int longest = 0, count;
        unordered_set<int> record;
        for ( int n : nums ) {
            count = 0;
            while ( record.find(n) == record.end() ) {
                record.insert(n);
                n = nums[n];
                ++count;
            }
            if ( count > longest ) longest = count;
        }
        return longest;
    }
};
