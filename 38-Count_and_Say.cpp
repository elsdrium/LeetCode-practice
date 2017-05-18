class Solution {
public:
    string countAndSay(int n) {
        if ( n == 1 ) return "1";
        string s = countAndSay(n-1);
        ostringstream oss;
        int count = 1;
        for ( int i=1; i!=s.size(); ++i ) {
            if ( s[i] == s[i-1] ) ++count;
            else {
                oss << count << s[i-1];
                count = 1;
            }
        }
        oss << count << s.back();
        return oss.str();
    }
};
