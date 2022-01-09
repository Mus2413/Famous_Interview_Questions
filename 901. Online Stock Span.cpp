class StockSpanner {
public:
    vector<int>v;
    int size=0;
    vector<int>ans;
    stack<int>s;
    int solve(vector<int>v,int n)
    {
        
        int i=n-1;
         int x=v[i];
            if(s.empty())
            {
                ans.push_back(-1);
                 s.push(i);
            }
            else if(v[s.top()]>v[i])
            {
                ans.push_back(s.top());
                 s.push(i);
            }
            else if(v[s.top()]<=v[i])
            {
                while(!s.empty() && v[s.top()]<=v[i])
                {
                    s.pop();
                }
                if(s.empty())
                    ans.push_back(-1);
                else
                {
                    ans.push_back(s.top());
                }
                 s.push(i);
            }
       
        
            ans[i]=i-ans[i];
        
        return ans[i];
    }
    StockSpanner() {
        
         
    }
    
    int next(int price) {
        v.push_back(price);
        size++;
        
        return solve(v,size);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */