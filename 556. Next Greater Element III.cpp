class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int x=s.length(),i;
        for( i=x-2;i>=0;i--)
        {
            if(s[i]<s[i+1])
                break;
                
        }
        if(i<0)
            return -1;
        
        int j;
        for(j=x-1;j>i;j--)
        {
            if(s[j]>s[i])
            {
                //cout<<s[i]<<" "<<s[j]<<" ";
                swap(s[i],s[j]);
                break;
                
            }
        }
        //cout<<s<<endl;
        reverse(s.begin()+i+1,s.end());
       // string z=to_string(2147483647);
        long long int ans=stol(s);
        cout<<ans<<endl;
        return ans>2147483647?-1:ans;
      
        
    }
};