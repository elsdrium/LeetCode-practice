class Trie {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string prefix, word;
        TrieNode(const string& px) : prefix(px), word() { }
    };
    TrieNode* root;
public:
    Trie() {
        this->root = new TrieNode(string());
    }
    
    void insert(string word) {
        TrieNode* tn = this->root;
        for ( int i=0; i!=word.size(); ++i ) {
            if ( tn->children[word[i] - 'a'] == nullptr )
                tn->children[word[i] - 'a'] = new TrieNode(word.substr(0, i+1));
            tn = tn->children[word[i] - 'a'];
        }
        tn->word = word;
    }
    
    bool search(string word) {
        TrieNode* tn = this->root;
        for ( int i=0; i!=word.size(); ++i ) {
            if ( tn->children[word[i] - 'a'] == nullptr )
                return false;
            tn = tn->children[word[i] - 'a'];
        }
        return tn->word == word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* tn = this->root;
        for ( int i=0; i!=prefix.size(); ++i ) {
            if ( tn->children[prefix[i] - 'a'] == nullptr )
                return false;
            tn = tn->children[prefix[i] - 'a'];
        }
        return true;
    }
};
