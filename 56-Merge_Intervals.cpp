class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if ( intervals.empty() ) return intervals;
        int i = 0, j = 0;
        vector<Interval> &sils = intervals, result;
        sort(sils.begin(), sils.end(), [&](Interval a, Interval b){ return a.start < b.start; });
        while ( j != sils.size() ) {
            if ( sils[i].end < sils[j].start ) {
                result.push_back(sils[i]);
                i = j;
            }
            sils[i].end = max(sils[i].end, sils[j++].end);
        }
        result.push_back(sils[i]);
        return result;
    }
};
