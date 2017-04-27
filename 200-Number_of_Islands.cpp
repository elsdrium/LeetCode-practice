class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if ( grid.empty() ) return 0;
        int li, lj;
        vector<vector<int>> land(grid.size(), vector<int>(grid[0].size()));
        map<int, int> lmap;
        for ( int i=0; i!=grid.size(); ++i ) {
            for ( int j=0; j!=grid[0].size(); ++j ) {
                if ( grid[i][j] == '0' ) continue;
                if ( i == 0 || grid[i-1][j] == '0' ) li = 0;
                else li = land[i-1][j];
                if ( j == 0 || grid[i][j-1] == '0' ) lj = 0;
                else lj = land[i][j-1];
                if ( li && lj ) {
                    while ( lmap[li] != li ) li = lmap[li];
                    while ( lmap[lj] != lj ) lj = lmap[lj];
                    if ( li == lj ) land[i][j] = li;
                    else if ( li < lj ) {
                        land[i][j] = li;
                        lmap[lj] = li;
                    }
                    else {
                        land[i][j] = lj;
                        lmap[li] = lj;
                    }
                }
                else {
                    if ( !li && !lj ) {
                        int q = lmap.size()+1;
                        lmap[q] = q;
                        land[i][j] = q;
                        continue;
                    }
                    if ( li ) {
                        while ( lmap[li] != li ) li = lmap[li];
                        land[i][j] = li;
                    }
                    if ( lj ) {
                        while ( lmap[lj] != lj ) lj = lmap[lj];
                        land[i][j] = lj;
                    }
                }
            }
        }
        set<int> lset;
        for ( auto &q : lmap ) {
            li = q.first;
            while ( lmap[li] != li ) li = lmap[li];
            lset.insert(li);
        }
        return lset.size();
    }
};
