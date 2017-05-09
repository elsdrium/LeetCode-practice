class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int sum;
        unordered_map<int, int> umap;
        for ( auto& row : wall )
            for ( int i=0, sum=0; i!=row.size()-1; ++i ) {
                sum += row[i];
                umap[sum] = umap.find(sum) == umap.end() ? 1 : umap[sum]+1;
            }
        return wall.size() - (umap.empty() ? 0 : max_element(umap.begin(), umap.end(),
                [&](const pair<int, int>& x, const pair<int, int>& y){return x.second < y.second;}
                )->second);
    }
};
