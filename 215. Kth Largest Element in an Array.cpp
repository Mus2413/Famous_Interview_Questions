class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto &c:nums){
            minHeap.push(c);
            if(minHeap.size()> k) minHeap.pop();
        }
        return minHeap.top();
    }
};