class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                i++;
            }
            else
            {
                
                swap(nums1[i],nums2[j]);
                cout<<j<<" "<<n<<endl;
                for(int k=j;k<n-1;k++)
                {
                    if(nums2[k]>nums2[k+1])
                        swap(nums2[k],nums2[k+1]);
                    else
                        break;
                }
                for(int k=j;k<n;k++){
                    cout<<nums2[k]<<" ";
                } 
                cout<<endl;
                
                
            }
        }
        if(i==m && j<n)
        {
            while(j<n)
            {
                nums1[i]=nums2[j];
                j++;
                i++;
            }
        }
       return ;
    }
};