class ModifiedTrie {
public:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word;
        TrieNode() : word() { }
    };
    TrieNode *pool, *root;
    int count;
    ModifiedTrie(TrieNode *stack_pool) {
        this->count = 0;
        this->pool = stack_pool;
        this->root = this->pool + this->count++;
    }
    void insert(const string& word) {
        TrieNode* tn = this->root;
        for ( int i=0; i!=word.size(); ++i ) {
            if ( tn->children[word[i] - 'a'] == nullptr )
                tn->children[word[i] - 'a'] = this->pool + this->count++;
            tn = tn->children[word[i] - 'a'];
        }
        tn->word = word;
    }
};

class Solution {
    vector<string> result;
    void dfs(const ModifiedTrie& mt, const string &word, int start, int size, ModifiedTrie::TrieNode *curr) {
        if ( start + size > word.size() || (this->result.size() && this->result.back() == word) ) return;
        char c = word[start + size - 1];
        if ( curr->children[c - 'a'] == nullptr ) return;
        curr = curr->children[c - 'a'];
        if ( word.substr(start, size) == curr->word ) {
            if ( start && start + size == word.size() )
                this->result.push_back(word);
            else dfs(mt, word, start+size, 1, mt.root);
        }
        dfs(mt, word, start, size+1, curr);
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<ModifiedTrie::TrieNode> pool(65536);
        ModifiedTrie mt(&pool[0]);
        this->result.clear();
        for ( const string& word : words ) {
            mt.insert(word);
        }
        for ( const string& word : words )
            dfs(mt, word, 0, 1, mt.root);
        return this->result;
    }
};
