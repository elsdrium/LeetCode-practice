class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        multiset<int> tset;
        int hh, mm, result;
        for ( auto &s : timePoints ) {
            sscanf(s.c_str(), "%d:%d", &hh, &mm);
            tset.insert(hh*60 + mm);
        }
        result = (24*60 + *tset.begin() - *tset.rbegin()) % (24*60);
        auto first = tset.begin(), second = ++tset.begin();
        while ( second != tset.end() ) {
            if ( *second - *first < result )
                result = *second - *first;
            ++first, ++second;
        }
        return result;
    }
};
