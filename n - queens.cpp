class Solution {
public:
    vector<vector<string>> ans;  
	
	//This is to check if the given row and column are safe for queen to sit. 
    bool isSafe(int r, int c, int n, vector<vector<int>> &v){
        for(int i=0;i<c;i++)
        {
            if(v[r][i])
                return 0;
        }
        for(int i=r,j=c;i>=0&&j>=0;i--,j--)
        {
            if(v[i][j])
                return 0;
        }
        for(int i=r,j=c;j>=0&&i<n;i++,j--)
        {
            if(v[i][j])
                return 0;
        }
        return 1;
    }
    bool rec(int c, int n, vector<vector<int>> &v) {
        if(c==n) return 1;
        
        for(int i=0;i<n;i++)
        {
            if(isSafe(i,c,n,v)){
                v[i][c]=1;
                if(rec(c+1,n,v)){
                    vector<string> v2(n,string(n,'.'));
                    for(int i=0;i<n;i++)
                    {
                        for(int j=0;j<n;j++)
                        {
                            if(v[i][j]==1)
                                v2[i][j]='Q';
                        }
                    }
                    ans.push_back(v2);
                }
                v[i][c]=0;
            }
        }
        return 0;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> v(n,vector<int>(n,0));
		
		// We will start from col=0 here:
        bool an=rec(0,n,v);
        return ans;
    }
};