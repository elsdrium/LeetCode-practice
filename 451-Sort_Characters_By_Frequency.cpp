class Solution {
public:
    string frequencySort(string s) {
        int curr = 0, cnt[256] = {0};
        multimap<int, char, greater<int>> freq_order;
        for ( char &c : s ) ++cnt[int(c)];
        for ( int i = 0; i < 256; ++i )
            if ( cnt[i] )
                freq_order.insert({cnt[i], char(i)});
        for ( auto &p : freq_order ) {
            for ( int i = 0; i < p.first; ++i )
                s[curr+i] = p.second;
            curr += p.first;
        }
        return s;
    }
};
