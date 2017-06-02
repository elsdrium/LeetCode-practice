class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        int start = 0, zcount = 0, dcount = 0;
        char d = '9';
        for ( int i=0; i != num.size() && dcount != k; ++i ) {
            if ( num.size() - start <= k - dcount ) { num.clear(); break; }
            if ( num[i] == '0' && i - zcount <= k ) {
                dcount = i - zcount;
                while ( i != num.size() && num[i] == '0' ) ++zcount, num[i++] = 'Q';
                start = i, d = num[i];
            }
            if ( num[i] < d ) {
                for ( char c=d; c!=num[i]; --c )
                    for ( int j=start; j != i && dcount != k; ++j )
                        if ( num[j] == c ) num[j] = 'Q', ++dcount;
            }
            d = num[i];
        }
        for ( int i=start; i<num.size(); ++i )
            if ( '0' <= num[i] && '9' >= num[i] ) result += num[i];
        if ( result.size() > num.size() - k ) result = result.substr(0, num.size()-k);
        return result.empty() ? "0" : result;
    }
};
