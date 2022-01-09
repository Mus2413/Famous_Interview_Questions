class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(empty())
        {
            return -1;
        }
        else
        {
            while(s1.size()>1)
            {
                s2.push(s1.top());
                s1.pop();
            }
            int x=s1.top();
            s1.pop();
            while(s2.size()>0)
            {
                s1.push(s2.top());
                s2.pop();
            }
            
            return x;
        }
    }
    
    int peek() {
         if(empty())
        {
            return -1;
        }
        else
        {
            while(s1.size()>1)
            {
                s2.push(s1.top());
                s1.pop();
            }
            int x=s1.top();
            s1.pop();
            s2.push(x);
            while(s2.size()>0)
            {
                s1.push(s2.top());
                s2.pop();
            }
            return x;
        }
    }
    
    bool empty() {
        if(s1.empty())
            return true;
        else
            return false;
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