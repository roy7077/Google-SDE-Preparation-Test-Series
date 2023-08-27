class Solution {
    public:
    int splitArray(int nums[] ,int n, int k) {
        
        int maxi=-1e9;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(nums[i],maxi);
            sum+=nums[i];
        }

        int ans=0;
        while(maxi<=sum)
        {
            int mid=(maxi+sum)/2;
            int cnt=0;
            int tempsum=0;
            for(int i=0;i<n;i++)
            {
                if(tempsum+nums[i]<=mid)
                tempsum+=nums[i];
                else
                {
                    tempsum=nums[i];
                    cnt++;
                }
            }
            cnt++;

            if(cnt<=k)
            {
                ans=mid;
                sum=mid-1;
            }
            else
            maxi=mid+1;
        }

        return ans;
    }
};