class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums(nums.size());
        string result;
        int i;
        for ( i=0; i!=nums.size(); ++i )
            str_nums[i] = to_string(nums[i]);
        sort(str_nums.begin(), str_nums.end(), [&](string a, string b){ return a+b>b+a; });
        for ( auto& str : str_nums ) result += str;
        for ( i=0; result[i] == '0' && i!=result.size()-1; ++i );
        return result.substr(i, result.size()-i);
    }
};
