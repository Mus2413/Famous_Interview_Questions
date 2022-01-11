class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int i,j,ans=-1, r=arr.size(), c = arr[0].size(), totalOranges = 0;
        
        queue<pair<int,int>> q;
        
        for(i=0; i<r; i++){
            for(j=0; j<c; j++){
                if(arr[i][j] == 1)
                    totalOranges++;
                else if(arr[i][j] == 2)
                    q.push({i,j});
            }
        }
        
        if(totalOranges == 0)
            return 0;
        
        while(!q.empty()){
            ans++;
            int s = q.size();
            
            if(totalOranges == 0)
                return ans;
            
            while(s--){
                auto p = q.front();
                int x = p.first, y = p.second;
                                
                arr[x][y] = -1;
                
                if(x>0 && arr[x-1][y] == 1){
                    arr[x-1][y] = 2;
                    q.push({x-1,y});
                    totalOranges--;
                }
                if(x<r-1 && arr[x+1][y] == 1){
                    arr[x+1][y] = 2;
                    q.push({x+1,y});
                    totalOranges--;
                }
                if(y>0 && arr[x][y-1] == 1){
                    arr[x][y-1] = 2;
                    q.push({x,y-1});
                    totalOranges--;
                }
                if(y<c-1 && arr[x][y+1] == 1){
                    arr[x][y+1] = 2;
                    q.push({x,y+1});
                    totalOranges--;
                }
                
                q.pop();
            }
        }
                        
        return -1;
    }
};