class Solution {
public:
    void heapify(vector<int>& nums,int n,int i)
    {
        int left=2*i+1;
        int right=2*i+2;
        int temp=i;
        if(left<n && nums[temp]<nums[left])
        {
            temp=left;
        }
        if(right<n && nums[temp]<nums[right])
        {
            temp=right;
        }
        if(temp!=i)
        {
            swap(nums[i],nums[temp]);
            heapify(nums,n,temp);
        }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(nums,n,i);
        }
        for(int i=n-1;i>0;i--)
        {
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
        return nums;
        
    }
};