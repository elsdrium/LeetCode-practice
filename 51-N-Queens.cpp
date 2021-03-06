class Solution {
    vector<vector<string>> solutions;
    inline bool checkAttack(vector<string>& board, int x, int y) {
        for ( int i = 1 ; i <= x ; ++i ) {
            if ( board[x-i][y] == 'Q' ||
                 (y - i >= 0 && board[x-i][y-i] == 'Q') ||
                 (y + i <= board.size() && board[x-i][y+i] == 'Q')
               ) return true;
        }
        return false;
    }
    void backtrackingNQueens(vector<string>& board, int x) {
        if ( x == board.size() ) {
            this->solutions.push_back(board);
            return;
        }

        for ( int i = 0 ; i < board.size() ; ++i ) {
            if ( checkAttack(board, x, i) ) continue;
            board[x][i] = 'Q';
            backtrackingNQueens(board, x+1);
            board[x][i] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrackingNQueens(board, 0);
        return this->solutions;
    }
};
