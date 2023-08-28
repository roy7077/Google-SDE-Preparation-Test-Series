class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N)
        return -1;
        
        int l=-1e9;
        int r=0;
        
        for(int i=0;i<N;i++)
        {
            l=max(A[i],l);
            r+=A[i];
        }
        
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int cnt=0;
            int tempsum=0;
            for(int i=0;i<N;i++)
            {
                if(tempsum+A[i]<=mid)
                tempsum+=A[i];
                else
                {
                    tempsum=A[i];
                    cnt++;
                }
            }
            
            cnt++;
            
            if(cnt<=M)
            {
                ans=mid;
                r=mid-1;
            }
            else
            l=mid+1;
        }
        
        return ans;
    }
};