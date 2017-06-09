class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int count[1<<(sizeof(char)*8)] = {0};
        for ( int i=0; i!=secret.size(); ++i )
            if ( secret[i] == guess[i] ) {
                ++bulls;
                guess[i] = '\0';
            }
            else ++count[secret[i]];
        for ( char &c : guess )
            if ( count[c] ) {
                --count[c];
                ++cows;
            }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
