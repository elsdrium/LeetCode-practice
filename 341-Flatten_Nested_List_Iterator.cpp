class NestedIterator {
    vector<vector<NestedInteger>::const_iterator> start, end;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        start.push_back(nestedList.begin());
        end.push_back(nestedList.end());
    }

    int next() {
        while ( true ) {
            if ( start.back() != end.back() ) {
                if ( start.back()->isInteger() ) return (start.back()++)->getInteger();
                auto &nl = (start.back()++)->getList();
                start.push_back(nl.begin());
                end.push_back(nl.end());
            }
            else start.pop_back(), end.pop_back();
        }
        return numeric_limits<int>::min();
    }

    bool hasNext() {
        while ( start.size() ) {
            if ( start.back() != end.back() ) {
                if ( start.back()->isInteger() ) return true;
                auto &nl = (start.back()++)->getList();
                start.push_back(nl.begin());
                end.push_back(nl.end());
            }
            else start.pop_back(), end.pop_back();
        }
        return false;
    }
};
