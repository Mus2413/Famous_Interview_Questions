bool solve(int n,vector<int>time,long long mid,int m)
{
    int sum=0,count=1;
    for(int i=0;i<time.size();i++)
    {
        if(time[i]>mid)
            return false;
        if(sum+time[i]>mid)
        {
            count++;
            if(count>n)
                return false;
            sum=time[i];
        }
        else
        {
            sum+=time[i];
        }
        
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    int st=0,end=0;
    for(int i=0;i<time.size();i++)
    { 
        end+=time[i];
    }
    long long mid=0,ans=INT_MAX;
    while(st<=end)
    {
         mid=(end+st)/2;
        if(solve(n,time,mid,m))
        {
            ans=min(ans,mid);
            end=mid-1;
        }
        else
        {
            st=mid+1;
        }
    }
    return ans;
}