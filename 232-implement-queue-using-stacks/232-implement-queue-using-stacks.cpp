class MyQueue {
public:
    stack<int> s1;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        stack<int> s2;
        while(!s1.empty()){
            int a=s1.top();
            s1.pop();
            s2.push(a);
        }
        int t=s2.top();
        s2.pop();
        while(!s2.empty()){
            int a=s2.top();
            s2.pop();
            s1.push(a);
        }
        return t;
    }
    
    int peek() {
        stack<int> s2;
        while(!s1.empty()){
            int a=s1.top();
            s1.pop();
            s2.push(a);
        }
        int t=s2.top();
        while(!s2.empty()){
            int a=s2.top();
            s2.pop();
            s1.push(a);
        }
        return t;
    }
    
    bool empty() {
        return s1.empty();
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