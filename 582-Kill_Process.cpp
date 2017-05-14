class Solution {
    multimap<int, int> ptable;
    vector<int> result;
    void helper(int kill) {
        result.push_back(kill);
        auto erange = ptable.equal_range(kill);
        while ( erange.first != erange.second ) helper((erange.first++)->second);
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        ptable.clear(), result.clear();
        for ( int i=0; i!=pid.size(); ++i )
            ptable.insert(make_pair(ppid[i], pid[i]));
        helper(kill);
        return result;
    }
};
