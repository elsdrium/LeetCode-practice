class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        for ( auto &v : board ) {
            s.clear();
            for ( char c : v ) {
                if ( c == '.' ) continue;
                if ( s.find(c) != s.end() ) return false;
                s.insert(c);
            }
        }
        for ( int j=0; j!=9; ++j ) {
            s.clear();
            for ( int i=0; i!=9; ++i ) {
                if ( board[i][j] == '.' ) continue;
                if ( s.find(board[i][j]) != s.end() ) return false;
                s.insert(board[i][j]);
            }
        }
        for ( int i=0; i!=9; i+=3 ) {
            for ( int j=0; j!=9; j+=3 ) {
                s.clear();
                for ( int k=0; k!=3; ++k )
                    for ( int l=0; l!=3; ++l ) {
                        if ( board[i+k][j+l] == '.' ) continue;
                        if ( s.find(board[i+k][j+l]) != s.end() ) return false;
                        s.insert(board[i+k][j+l]);
                    }
            }
        }
        return true;
    }
};
