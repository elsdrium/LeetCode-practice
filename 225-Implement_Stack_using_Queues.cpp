class MyStack {
    queue<int> _q;
public:
    MyStack() : _q() {
    }
    
    void push(int x) {
        vector<int> buffer;
        while ( this->_q.size() ) {
            buffer.push_back(this->_q.front());
            this->_q.pop();
        }
        this->_q.push(x);
        for ( int &elem : buffer ) this->_q.push(elem);
    }
    
    int pop() {
        int elem = this->_q.front();
        this->_q.pop();
        return elem;
    }
    
    int top() {
        return this->_q.front();
    }
    
    bool empty() {
        return this->_q.empty();
    }
};
