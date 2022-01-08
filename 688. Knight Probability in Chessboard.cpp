class Solution {
public:
    double knightProbability(int n, int k, int r, int c)
    {
        vector<pair<int,int>>d={{2,1},{-2,1},{2,-1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
        vector<vector<double>>dp1(n,vector<double>(n,0.0));
        vector<vector<double>>dp2(n,vector<double>(n,0.0));
        dp1[r][c]=1.0;
        auto is_safe=[&](int x,int y)
        {  
            return x>=0&&y>=0&&x<n&&y<n;
        };
        for(int move=1;move<=k;move++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                        double ans=(dp1[i][j]/8.0);
                        for(auto it:d)
                        {
                            int nx=i+it.first;
                            int ny=j+it.second;
                            if(is_safe(nx,ny))
                            {
                                dp2[nx][ny]+=ans;
                            }
                        }

                }
            }
            dp1=dp2;
            dp2=vector<vector<double>>(n,vector<double>(n,0.0));
        }
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=dp1[i][j];
            }
        }
        return ans;
    }
};