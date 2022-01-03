class Solution {
public:
    static bool comp(vector<int>a, vector<int>b)
    {
        if(a[0]<b[0])
            return true;
        else if(a[0]==b[0])
            return a[1]<b[1];
        else
            return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<int>temp;
        temp.push_back(intervals[0][0]);
        temp.push_back(intervals[0][1]);
        vector<vector<int>>ans;
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]<=temp[1])
            {
                temp[0]=min(temp[0],intervals[i][0]);
                temp[1]=max(temp[1],intervals[i][1]);
            }
            else
            {
                ans.push_back(temp);
                temp[0]=intervals[i][0];
                temp[1]=intervals[i][1];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};