class MinStack {
public:
    vector<pair<int, int> > stv;
    MinStack() {
        
    }
    
    void push(int val) {
        if(stv.empty()){
            pair<int, int> p = make_pair(val, val);
            stv.push_back(p);
        }
        else{
            pair<int, int> p;
            p.first = val;
            p.second = min(val, stv.back().second);
            stv.push_back(p);
        }
    }
    
    void pop() {
        stv.pop_back();
    }
    
    int top() {
       return stv.back().first; 
    }
    
    int getMin() {
        return stv.back().second;
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