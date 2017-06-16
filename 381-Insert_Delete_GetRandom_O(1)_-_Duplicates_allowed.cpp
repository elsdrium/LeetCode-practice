class RandomizedCollection {
    unordered_map<int, unordered_set<int>> umap;
    vector<int> vec;
public:
    RandomizedCollection() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if ( umap.find(val) == umap.end() ) {
            umap[val] = unordered_set<int>();
            umap[val].insert(vec.size());
            vec.push_back(val);
            return true;
        }
        umap[val].insert(vec.size());
        vec.push_back(val);
        return false;
    }
    
    bool remove(int val) {
        if ( umap.find(val) == umap.end() ) return false;
        umap[vec.back()].insert(*umap[val].begin());
        umap[vec.back()].erase(vec.size()-1);
        if ( vec.back() != val ) {
            swap(vec[*umap[val].begin()], vec.back());
            umap[val].erase(umap[val].begin());
        }
        vec.resize(vec.size() - 1);
        if ( umap[val].empty() ) umap.erase(val);
        return true;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};
