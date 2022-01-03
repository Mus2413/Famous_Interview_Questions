class Solution {
public:
   


    bool wordBreak(string s, vector<string>& wordDict) {
     vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i <= s.size(); ++i) {
            if (!dp[i]) continue;
            for (auto d: wordDict) {
                if (d.size() + i <= s.size() && s.substr(i, d.size()) == d) {
                    dp[i + d.size()] = true;
                }
            }
        }
        return dp.back();
    }
};