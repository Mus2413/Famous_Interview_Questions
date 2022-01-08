class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int size=n*n;
        cout<<size<<endl;
        int arr[size+1];
        memset(arr,0,sizeof(arr));
        int k=1;
        bool flag=false;
        bool vis[size+1];
        memset(vis,false,sizeof(vis));
        for(int i=n-1;i>=0;i--)
        {
            if(!flag)
            {
                for(int j=0;j<n;j++)
                {
                    arr[k]=board[i][j];
                    k++;
                }
            }
            else
            {
                for(int j=n-1;j>=0;j--)
                {
                    arr[k]=board[i][j];
                    k++;
                }
            }
            flag=!flag;
        }
        cout<<arr[size]<<endl;
        if(arr[size]!=-1)
            return -1;
        queue<pair<int,int>>q;
        q.push({1,0});
        while(!q.empty())
        {
            int x=q.front().first;
            int cost=q.front().second;
            q.pop();
            if(x==size)
                return cost;
            for(int i=1;i<=6;i++)
            {
                int y=x+i;
                if(y<=size )
                {
                    if(arr[y]!=-1)
                    {
                        y=arr[y];
                    }
                    if(vis[y]==false)
                    {
                        q.push({y,cost+1});
                        vis[y]=true;
                    }
                }
                
            }
        }
        return -1;
        
    }
};