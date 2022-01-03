class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=m-1,k=n-1,l=0;
        while(i<=k && l<=j)
        {
            if(i<=k)
            {
                for(int x=l;x<=j;x++)
                {
                    ans.push_back(matrix[i][x]);
                }
                i++;
            }
            if(j>=l)
            {
                for(int z=i;z<=k;z++)
                    ans.push_back(matrix[z][j]);
                j--;
            }
            if(k>=i)
            {
                for(int x=j;x>=l;x--)
                {
                    ans.push_back(matrix[k][x]);
                }
                k--;
            }
            if(l<=j)
            {
                for(int x=k;x>=i;x--)
                {
                    ans.push_back(matrix[x][l]);
                }
                l++;
            }
        }
        
        return ans;
    }
};