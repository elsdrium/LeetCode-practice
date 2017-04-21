class Solution {
public:
    string simplifyPath(string path) {
        string token, result;
        istringstream iss;
        vector<string> tokens;
        iss.str(path);
        while ( getline(iss, token, '/') ) {
            if ( token.empty() || token == "." ) continue;
            if ( token == ".." ) {
                if ( tokens.size() ) tokens.pop_back();
                continue;
            }
            tokens.push_back(token);
        }
        for ( auto &t : tokens ) result = result + "/" + t;
        return result.empty() ? "/" : result;
    }
};
