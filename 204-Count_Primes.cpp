class Solution {
public:
    int countPrimes(int n) {
        static vector<int> ptable = {2, 3, 5, 7, 11};
        int idx;
        for ( int p = ptable.back()+2; p < n; p+=2 ) {
            idx = upper_bound(ptable.begin(), ptable.end(), int(sqrt(p))) - ptable.begin();
            while ( idx >= 0 )
                if ( p % ptable[idx--] == 0 ) break;
            if ( idx < 0 ) ptable.push_back(p);
        }
        return lower_bound(ptable.begin(), ptable.end(), n) - ptable.begin();
    }
};
