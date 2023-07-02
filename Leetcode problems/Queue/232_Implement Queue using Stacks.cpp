class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
//         TC - O(n)
//         // step 1: s1 ko s2 me dalo
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
        
//         // step 2: Ad x to s1
//         s1.push(x);
        
//         //step 3: s2 ko s1 me dalo
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
        
        // O(1)
        s1.push(x);
    }
    
    int pop() {
        int top = -1;
        if(!s2.empty()){
            top = s2.top();
            s2.pop();
        }
        else{
            while(!s1.empty()){
               s2.push(s1.top());
               s1.pop();
             }
            top = s2.top();
            s2.pop();
        }
        return top;
    }
    
    int peek() {
        int front = -1;
         if(!s2.empty()){
            front = s2.top();
        }
        else{
            while(!s1.empty()){
               s2.push(s1.top());
               s1.pop();
             }
            front = s2.top();
        } 
        return front;
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */