#define ll long long
class Solution
{
    public:
    long long minTime(int arr[], int n, int k)
    {
        ll sum=0;
        int l=-1e9;
        
        for(int i=0;i<n;i++)
        {
            l=max(l,arr[i]);
            sum+=arr[i];
        }
        
        ll ans=0;
        while(l<=sum)
        {
            int mid=(l+sum)/2;
            ll cnt=0;
            ll tempsum=0;
            for(int i=0;i<n;i++)
            {
                if(arr[i]+tempsum<=mid)
                tempsum+=arr[i];
                else
                {
                    cnt++;
                    tempsum=arr[i];
                }
            }
            
            cnt++;
            if(cnt<=k)
            {
                ans=mid;
                sum=mid-1;
            }
            else
            l=mid+1;
        }
        
        return ans;
    }
};