class MinStack {
    list<int> data;
    multiset<int> uset;
public:
    MinStack() : uset(), data() {
    }
    
    void push(int x) {
        data.push_back(x);
        uset.insert(x);
    }
    
    void pop() {
        uset.erase(uset.find(this->top()));
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return *uset.begin();
    }
};
