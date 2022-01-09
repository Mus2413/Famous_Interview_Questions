int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int incom[n],out[n];
        memset(incom,0,sizeof(incom));
        memset(out,0,sizeof(out));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1)
                {
                    incom[j]++;
                    out[i]++;
                }
                
            }
        }
        for(int i=0;i<n;i++)
        {
            if(incom[i]==n-1 && out[i]==0)
            return i;
        }
        return -1;
    }