class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> record(numCourses, false);
        vector<set<int>> pre(numCourses), dep(numCourses);
        vector<int> result;
        int i, v;
        for ( auto &p : prerequisites ) {
            pre[p.first].insert(p.second);
            dep[p.second].insert(p.first);
        }
        while ( result.size() < numCourses ) {
            for ( i=0, v=-1; i!=pre.size(); ++i )
                if ( !record[i] && pre[i].empty() ) { v = i; break; }
            if ( v == -1 ) return vector<int>();
            do {
                result.push_back(v);
                record[v] = true;
                for ( auto &neighbor : dep[v] ) pre[neighbor].erase(v);
                for ( auto &neighbor : dep[v] )
                    if ( !record[neighbor] && pre[neighbor].empty() )
                        v = neighbor;
            } while ( v != result.back() );
        }
        return result;
    }
};
