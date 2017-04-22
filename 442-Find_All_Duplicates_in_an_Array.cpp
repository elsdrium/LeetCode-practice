class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> uset;
        vector<int> result;
        for ( auto &n : nums ) {
            if ( uset.find(n) == uset.end() ) uset.insert(n);
            else result.push_back(n);
        }
        return result;
    }
};
