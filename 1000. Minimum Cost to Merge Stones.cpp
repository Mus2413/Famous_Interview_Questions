class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if(n == 0) return -1;
        if((n-1) % (K-1) != 0) return -1;
        vector<int> psum(n+1);
        psum[0] = 0;
        for(int i = 0; i < n; i++){
            psum[i+1] = psum[i] + stones[i];
        }
       
        vector<vector<vector<int>>> dp(n,
                                       vector<vector<int>>(n,
                                       vector<int>(K+1, -1)));
        
        for(int i = 0; i < n; i++){
            dp[i][i][1] = 0; 
        }
        for(int len = 2; len <= n; len++){
            for(int i = 0, j; i <= n-len; i++){
                j = i + len - 1;
                
                for(int m = 2; m <= K; m++){
                    
                    if(len < m or (len - m) % (K-1) != 0) continue; 
                    for(int k = i; k < j; k++){
                        int left_len = k - i + 1;
                        int right_len = len - left_len;
                        
                        if((left_len - 1) % (K-1) != 0){
                            assert(dp[i][k][1] == -1);
                            continue;
                        }
                      
                        if(right_len < m-1 or (right_len - (m-1)) % (K-1) != 0){
                            assert(dp[k+1][j][m-1] == -1);
                            continue;
                        }
                        if(dp[i][j][m] == -1) dp[i][j][m] = dp[i][k][1] + dp[k+1][j][m-1];
                        else dp[i][j][m] = min(dp[i][j][m], dp[i][k][1] + dp[k+1][j][m-1]);
                    }
                }
                // Compute dp[i][j][1]
                if((len - 1) % (K-1) == 0){
                    assert(dp[i][j][K] != -1);
                    dp[i][j][1] = dp[i][j][K] + psum[j+1] - psum[i];
                }
            }
        }
        return dp[0][n-1][1];
    }
};