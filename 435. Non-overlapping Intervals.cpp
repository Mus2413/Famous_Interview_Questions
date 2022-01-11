class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector <pair <int, int>> intr;
        for (auto x : intervals) {
            intr.push_back({x[1], x[0]});
        }
        sort(intr.begin(), intr.end()); // Sort by end time
        
        int mx = -6e4;
        int ans = 0;
        for (auto x : intr) {
            if (x.second >= mx) {
                mx = x.first;
                continue;
            }
            ans++;
        }   
        return ans;
    }
};