class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
		
        int n = profit.size();
        vector<vector<int>> club;     
        
        for(int i = 0; i < n; i++){
            club.push_back({startTime[i], endTime[i], profit[i]});         
        }
       sort(club.begin(), club.end(), [](vector<int> &a, vector<int> &b){ return a[1] < b[1]; });      
        vector<int> dp(n,0);           
        
        for(int i = 0; i < n; i++){             
            if(i == 0){                       
                dp[i] = club[i][2];             
                continue;                       
            }
            dp[i] = club[i][2];
            int tempMax = 0;                 
            for(int j = i-1; j>=0; j--){        
                if(club[j][0] < club[i][0] && club[j][1] < club[i][1] && club[i][0] >= club[j][1]){
                    tempMax = max(tempMax, dp[j]);
                    break;                 
                }
            }
            
           
            dp[i] = max(dp[i]+tempMax, dp[i-1]);

        }
        return dp[n-1];             
    }
};