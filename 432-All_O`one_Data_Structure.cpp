class AllOne {
    struct CountNode {
        int val;
        unordered_set<string> kset;
        CountNode(int v, string k) : val(v), kset({k}) { }
    };
    struct RelationalCount {
        int val;
        list<CountNode>::iterator it;
        RelationalCount(int v=1) : val(1) { }
    };
    unordered_map<string, RelationalCount> umap;
    list<CountNode> lcn;
public:
    AllOne() { }
    
    void inc(string key) {
        if ( umap.find(key) != umap.end() ) {
            umap[key].val++;
            auto it = umap[key].it; ++it;
            if ( it == lcn.end() || it->val != umap[key].val ) {
                umap[key].it->kset.erase(key);
                lcn.insert(it, CountNode(umap[key].val, key));
            }
            else {
                umap[key].it->kset.erase(key);
                it->kset.insert(key);
            }
            it = umap[key].it++;
            if ( it->kset.empty() ) lcn.erase(it);
        }
        else {
            umap[key] = RelationalCount();
            if ( lcn.front().val != 1 )
                lcn.push_front(CountNode(1, key));
            else lcn.front().kset.insert(key);
            umap[key].it = lcn.begin();
        }
    }
    
    void dec(string key) {
        if ( umap.find(key) == umap.end() ) return;
        auto it = umap[key].it;
        if ( --umap[key].val ) {
            if ( umap[key].it == lcn.begin() || (--it)->val != umap[key].val )
                lcn.insert(umap[key].it, CountNode(umap[key].val, key));
            else {
                it = umap[key].it;
                (--it)->kset.insert(key);
            }
            it = umap[key].it--;
        }
        else umap.erase(key);
        it->kset.erase(key);
        if ( it->kset.empty() ) lcn.erase(it);
    }
    
    string getMaxKey() {
        return lcn.empty() ? "" : *lcn.back().kset.begin();
    }
    
    string getMinKey() {
        return lcn.empty() ? "" : *lcn.front().kset.begin();
    }
};
