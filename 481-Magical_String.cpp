class Solution {
public:
    int magicalString(int n) {
        static vector<char> S = {1, 2, 2};
        static int i = 2, last = 1;
        if ( n <= 0 ) return 0;
        while ( S.size() < n ) {
            S.push_back(last);
            if ( S[i++] != 1 ) S.push_back(last);
            last ^= 3;
        }
        return count(S.begin(), S.begin()+n, 1);
    }
};
