class Solution {
public:
    string convertToTitle(int n) {
        const char b = char('A' - 1);
        string result;
        while ( n ) {
            if ( n % 26 ) {
                result = char(b + n % 26) + result;
                n /= 26;
            }
            else {
                result = char(b + 26) + result;
                n = (n - 26) / 26;
            }
        }
        return result;
    }
};
