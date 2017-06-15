class RandomizedSet {
    unordered_map<int, int> umap;
    vector<int> vec;
public:
    RandomizedSet() {
        srand(time(0));
    }
    
    bool insert(int val) {
        if ( umap.find(val) != umap.end() ) return false;
        umap[val] = vec.size();
        vec.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if ( umap.find(val) == umap.end() ) return false;
        umap[vec.back()] = umap[val];
        swap(vec[umap[val]], vec.back());
        vec.resize(vec.size() - 1);
        umap.erase(val);
        return true;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
};
