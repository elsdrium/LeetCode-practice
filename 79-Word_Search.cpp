class Solution {
    vector<vector<bool>> record;
    bool dfs(const vector<vector<char>>& board, string word, int index, int i, int j) {
        if ( index == word.size() ) return true;
        if ( i && !record[i-1][j] && board[i-1][j] == word[index] ) {
            record[i-1][j] = true;
            if ( dfs(board, word, index+1, i-1, j) ) return true;
            record[i-1][j] = false;
        }
        if ( j && !record[i][j-1] && board[i][j-1] == word[index] ) {
            record[i][j-1] = true;
            if ( dfs(board, word, index+1, i, j-1) ) return true;
            record[i][j-1] = false;
        }
        if ( i != board.size()-1 && !record[i+1][j] && board[i+1][j] == word[index] ) {
            record[i+1][j] = true;
            if ( dfs(board, word, index+1, i+1, j) ) return true;
            record[i+1][j] = false;
        }
        if ( j != board[0].size()-1 && !record[i][j+1] && board[i][j+1] == word[index] ) {
            record[i][j+1] = true;
            if ( dfs(board, word, index+1, i, j+1) ) return true;
            record[i][j+1] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if ( word.empty() || board.empty() ) return false;
        record = vector<vector<bool>>(board.size(), vector<bool>(board[0].size()));
        for ( int i=0; i!=board.size(); ++i )
            for ( int j=0; j!=board[0].size(); ++j )
                if ( board[i][j] == word[0] ) {
                    record[i][j] = true;
                    if ( dfs(board, word, 1, i, j) ) return true;
                    record[i][j] = false;
                }
        return false;
    }
};
