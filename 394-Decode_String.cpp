class Solution {
    string recursiveDecode(string &s, int &start) {
        int i, j, times;
        string result, temp;
        for ( i = start; i < s.size(); i = start ) {
            while ( i < s.size() && s[i] != ']' && ('9' < s[i] || '0' > s[i]) ) ++i;
            result += s.substr(start, i - start);
            if ( s[i] == ']' ) break;
            for ( j = i; j < s.size() && '9' >= s[j] && '0' <= s[j]; ++j );
            times = (i == j ? 0 : stoi(s.substr(i, j - i)));
            start = j + 1;
            temp = recursiveDecode(s, start);
            for ( j = 0; j < times; ++j ) result += temp;
        }
        start = i + 1;
        return result;
    }
public:
    string decodeString(string s) {
        int start = 0;
        return recursiveDecode(s, start);
    }
};
