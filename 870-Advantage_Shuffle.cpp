class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> mset(A.begin(), A.end());
        vector<int> ret; ret.reserve(A.size());
        for ( int i = 0 ; i < B.size() ; ++i ) {
            auto it = mset.upper_bound(B[i]);
            if ( it == mset.end() ) {
                ret.push_back(*mset.begin());
                mset.erase(mset.begin());
            }
            else {
                ret.push_back(*it);
                mset.erase(it);
            }
        }
        return ret;
    }
};

static int desyncio = []() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return 0;
}();
