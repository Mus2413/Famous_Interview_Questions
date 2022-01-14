class MedianFinder {
public:
    priority_queue<int>l;
    priority_queue<int,vector<int>,greater<int>>r;
    double med;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(l.size()==0 && r.size()==0)
        {
            med=num;
            l.push(med);
        }
        else if(l.size()>r.size())
        {
            if(num<med)
            {
                r.push(l.top());
                l.pop();
                l.push(num);
            }
            else
            {
                r.push(num);
            }
            med=(l.top()+r.top())/2.0;
        }
        else if(l.size()<r.size())
        {
            if(num<med)
            {
                
                l.push(num);
            }
            else
            {
                l.push(r.top());
                r.pop();
                r.push(num);
            }
            med=(l.top()+r.top())/2.0;
        }
        else
        {
            if(num<med)
            {
                
                l.push(num);
                med=(double)l.top();
            }
            else
            {
                r.push(num);
                med=(double)r.top();
            }
            
        }
        
    }
    
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */