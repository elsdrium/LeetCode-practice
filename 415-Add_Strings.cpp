class Solution {
public:
    string addStrings(string num1, string num2) {
        bool plus = false;
        int i = num1.size()-1, j = num2.size()-1, d1, d2;
        string result;
        while ( i >= 0 || j >=0 || plus ) {
            d1 = i >= 0 ? num1[i]-'0' : 0;
            d2 = j >= 0 ? num2[j]-'0' : 0;
            d1 += d2 + int(plus);
            result.push_back(static_cast<char>(d1%10 + '0'));
            plus = d1 > 9;
            i--, j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
