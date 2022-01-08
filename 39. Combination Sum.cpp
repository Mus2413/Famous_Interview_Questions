class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {        
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        recrusive(candidates, curr, 0, target);
        return res;
    }
    
    void recrusive(vector<int> &candidates, vector<int> &curr, int idx,int target)
    {
        
        if(target == 0) {
            res.push_back(curr);
            return;
        }
        if(idx == candidates.size() ) return ;
        
        for(int i = idx; i < candidates.size(); i++)
        {
            if(candidates[i] <= target){
                curr.push_back(candidates[i]);
                recrusive(candidates, curr, i, target - candidates[i]);
                curr.pop_back();
            }
            else return;
        }
        
    }
    
};