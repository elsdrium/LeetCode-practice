class Solution {
    inline int dist(const vector<int> &u, const vector<int> &v) const {
        return abs(u[0] - v[0]) + abs(u[1] - v[1]);
    }
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int result = 0;
        auto it = max_element(nuts.begin(), nuts.end(), [&](vector<int>& n1, vector<int>& n2){
            return dist(n1, tree) - dist(n1, squirrel) < dist(n2, tree) - dist(n2, squirrel);
        });
        result += dist(squirrel, *it);
        result += dist(*it, tree);
        nuts.erase(it);
        for ( auto &nut : nuts ) result += 2*dist(nut, tree);
        return result;
    }
};
