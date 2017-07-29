class Solution {
    class ModifiedTrie {
    public:
        struct TrieNode {
            TrieNode* children[26] = {nullptr};
            string word;
            TrieNode() : word() { }
            ~TrieNode() {
                for ( int i = 0; i < 26; ++i )
                    if ( children[i] != nullptr ) delete children[i];
            }
        };
        TrieNode *root;
        ModifiedTrie() {
            this->root = new TrieNode();
        }
        ~ModifiedTrie() {
            delete this->root;
        }
        void clear() {
            delete this->root;
            this->root = new TrieNode();
        }
        void insert(const string& word) {
            TrieNode* tn = this->root;
            for ( int i=0; i!=word.size(); ++i ) {
                if ( tn->children[word[i] - 'a'] == nullptr )
                    tn->children[word[i] - 'a'] = new TrieNode();
                tn = tn->children[word[i] - 'a'];
            }
            tn->word = word;
        }
    };
    void dfs(vector<vector<char>> &board, int x, int y, ModifiedTrie::TrieNode *curr) {
        char c = board[x][y];
        if ( curr->children[c - 'a'] == nullptr ) return;
        curr = curr->children[c - 'a'];
        if ( curr->word.size() ) {
            this->result.push_back(curr->word);
            curr->word.clear();
        }
        board[x][y] = 0;
        if ( x && board[x-1][y] ) dfs(board, x-1, y, curr);
        if ( y && board[x][y-1] ) dfs(board, x, y-1, curr);
        if ( x < board.size()-1 && board[x+1][y] ) dfs(board, x+1, y, curr);
        if ( y < board[0].size()-1 && board[x][y+1] ) dfs(board, x, y+1, curr);
        board[x][y] = c;
    }
    vector<string> result;
    ModifiedTrie mt;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        this->result.clear();
        this->mt.clear();
        for ( const string& word : words ) mt.insert(word);
        for ( int i = 0; i < board.size(); ++i )
            for ( int j = 0; j < board[0].size(); ++j )
                dfs(board, i, j, this->mt.root);
        return this->result;
    }
};
