/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        int merge_start, merge_end, si = 0, ei = intervals.size() - 1, mi;

        if ( intervals.empty() ) {
            ret.push_back(newInterval);
            goto END;
        }

        while ( ei - si > 1 ) {
            mi = (ei + si) / 2;
            if ( newInterval.start < intervals[mi].start ) ei = mi;
            else si = mi;
        }
        if ( newInterval.start <= intervals[si].end ) merge_start = si;
        else if ( newInterval.start <= intervals[ei].end ) merge_start = ei;
        else merge_start = ei + 1;

        ei = intervals.size() - 1;
        while ( ei - si > 1 ) {
            mi = (ei + si) / 2;
            if ( newInterval.end < intervals[mi].end ) ei = mi;
            else si = mi;
        }
        if ( newInterval.end <= intervals[si].end ) merge_end = si;
        else if ( newInterval.end <= intervals[ei].end ) merge_end = ei;
        else merge_end = ei + 1;

        for ( int i = 0 ; i < merge_start ; ++i )
            ret.push_back(intervals[i]);

        if ( merge_start == intervals.size() ) {
            ret.push_back(newInterval);
            goto END;
        }
        else ret.push_back(Interval(
                    min(newInterval.start, intervals[merge_start].start),
                    newInterval.end)
                );
        if ( merge_end == intervals.size() ) goto END;
        if ( intervals[merge_end].start > ret.back().end )
            ret.push_back(intervals[merge_end]);
        else
            ret.back().end = intervals[merge_end].end;

        for ( int i = merge_end + 1 ; i < intervals.size() ; ++i )
            ret.push_back(intervals[i]);

        END:
        return ret;
    }
};
