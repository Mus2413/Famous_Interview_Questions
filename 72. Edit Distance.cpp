class Solution {
public:
    int LCS(string a,string b,int n,int m)
    {
        int t[n+1][m+1];
        for(int i=0;i<=n;i++)
            t[i][0]=i;
        for(int i=0;i<=m;i++)
            t[0][i]=i;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    t[i][j]=t[i-1][j-1];
                else
                    t[i][j]=1+min(t[i-1][j],min(t[i][j-1],t[i-1][j-1]));
            }
        }
        return t[n][m];
    }
    int minDistance(string word1, string word2) {
        int a=LCS(word1,word2,word1.size(),word2.size());
        return a;
    }
    
};