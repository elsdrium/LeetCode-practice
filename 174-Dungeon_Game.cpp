class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>> hp(dungeon.size(), vector<int>(dungeon[0].size()));
        hp[dungeon.size()-1][dungeon[0].size()-1] = 1 - min(dungeon[dungeon.size()-1][dungeon[0].size()-1], 0);
        for ( int i=hp.size()-2; i>=0; --i )
            hp[i][hp[0].size()-1] = max(hp[i+1][hp[0].size()-1] - dungeon[i][hp[0].size()-1], 1);
        for ( int j=hp[0].size()-2; j>=0; --j )
            hp[hp.size()-1][j] = max(hp[hp.size()-1][j+1] - dungeon[hp.size()-1][j], 1);
        for ( int i=hp.size()-2; i>=0; --i )
            for ( int j=hp[0].size()-2; j>=0; --j ) {
                hp[i][j] = max(min(hp[i+1][j] - dungeon[i][j], hp[i][j+1] - dungeon[i][j]), 1);
            }
        return hp[0][0];
    }
};
