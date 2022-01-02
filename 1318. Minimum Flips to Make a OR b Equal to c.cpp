class Solution {
public:
    int minFlips(int a, int b, int c) {
        bitset<32>a1(a);
        bitset<32>b1(b);
         bitset<32>c1(c);
        int n=a1.size(),m=b1.size();
        int cnt=0;
        int i=0,j=0;
        int k=0;
        while(i<n && j<m)
        {
            int x=a1[i]|b1[i];
            if(x!=c1[k])
            {
                if(c1[k]==0)
                {
                    if(a1[i]==1 && b1[i]==0)
                        cnt++;
                    else if(a1[i]==0 && b1[i]==1)
                        cnt++;
                    else
                        cnt+=2;
                }
                else
                {
                    cnt++;
                }
            }
            i++;
            k++;
            j++;
        }
        if(i==n && j<m)
        {
            while(j<m)
            {
                if(b1[j]!=c1[k])
                    cnt++;
                
                j++;
                k++;
            }
        }
        if(j==m && i<n)
        {
            while(i<n)
            {
                if(a1[i]!=c1[k])
                    cnt++;
                
                i++;
                k++;
            }
        }
        return cnt;
        
    }
};