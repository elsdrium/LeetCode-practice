class Solution {
    void DFSTraversal(int n, const vector<vector<int>> &M, vector<bool> &visited) {
        for ( int i = 0; i < M.size(); ++i ) {
            if ( M[n][i] && !visited[i] ) {
                visited[i] = true;
                DFSTraversal(i, M, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        vector<bool> visited(M.size(), false);
        for ( int i = 0; i < M.size(); ++i ) {
            if ( !visited[i] ) {
                count++;
                visited[i] = true;
                DFSTraversal(i, M, visited);
            }
        }
        return count;
    }
};

static const auto ___ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
