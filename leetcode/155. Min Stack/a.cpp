class MinStack {
public:
    vector<pair<int, int>> stk;
    int myMin;
    MinStack() {
        this->myMin = INT_MAX;
    }
    
    void push(int val) {
        this->myMin = min(this->myMin, val);
        this->stk.emplace_back(make_pair(val, this->myMin)); // record current found min for each stack elem
    }
    
    void pop() {
        this->stk.pop_back();
        if (this->stk.empty()) this->myMin = INT_MAX;
        else this->myMin = this->stk.back().second;
    }
    
    int top() {
        return this->stk.back().first;
    }
    
    int getMin() {
        return this->stk.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */