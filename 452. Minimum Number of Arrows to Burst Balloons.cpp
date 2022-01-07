class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int start = points[0][0], end = points[0][1], groups = 1;
        for (int i = 1; i < points.size(); ++i)
        {
            start = max(start, points[i][0]);
            end = min(end, points[i][1]);
            if (start > end)
            {
                groups++;
                start = points[i][0];
                end = points[i][1];
            }
        }
        return groups;
    }
};