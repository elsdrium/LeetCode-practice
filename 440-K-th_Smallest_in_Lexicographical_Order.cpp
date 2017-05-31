class Solution {
public:
    int findKthNumber(int n, int k) {
        if ( n < 10 ) return k;
        string result, ns = to_string(n);
        int m = 0, base;
        --k;
        for ( int i=1; i<=9; ++i ) {
            m = stoi(string(ns.size()-1, '1'));
            if ( i == ns[0] - '0' )
                m += stoi(ns.substr(1, ns.size()-1)) + 1;
            if ( i < ns[0] - '0' )
                m = stoi(string(ns.size(), '1'));
            if ( k < m ) {
                result += char('0' + i);
                if ( ns.size() == 2 && i > ns[0]-'0' ) break;
                base = stoi(string(ns.size() - (1 + int(i>ns[0]-'0')), '1'));
                break;
            }
            k -= m;
        }
        if ( result[0] == ns[0] ) {
            int longer_count = 0;
            for ( int i=1; i!=ns.size(); ++i )
                longer_count += (stoi(ns.substr(1, ns.size()-i)) + 1);
            if ( k > longer_count ) { k -= (stoi(ns.substr(1, ns.size()-1)) + 1); base /= 10; }
        }
        while ( k ) {
            --k;
            result += ('0' + k / base);
            k %= base; base /= 10;
        }
        return stoi(result);
    }
};
