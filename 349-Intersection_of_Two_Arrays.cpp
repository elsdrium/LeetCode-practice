class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset;
        vector<int> result;
        for ( int &num : nums1 ) uset.insert(num);
        for ( int &num : nums2 ) {
            auto it = uset.find(num);
            if ( it != uset.end() ) {
                result.push_back(num);
                uset.erase(it);
            }
        }
        return result;
    }
};
