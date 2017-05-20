class Solution {
public:
    int hIndex(vector<int>& citations) {
        if ( citations.empty() ) return 0;
        sort(citations.begin(), citations.end());
        long long s = 0, t = citations.size()-1, m;
        while ( t - s > 1 ) {
            m = ( s + t ) / 2;
            if ( citations[m] >= citations.size() - m ) {
                if ( citations[m-1] <= citations.size() - m ) s = m;
                else t = m;
            }
            else s = m;
        }
        if ( citations[t] >= citations.size()-t && citations[t-1] <= citations.size()-t )
            return citations.size() - t;
        else if ( citations[s] >= citations.size()-s && citations[s-1] <= citations.size()-s )
            return citations.size() - s;
        return 0;
    }
};
