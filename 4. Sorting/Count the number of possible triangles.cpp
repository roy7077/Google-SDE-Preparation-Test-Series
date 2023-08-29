class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr,arr+n,greater<int>());
        int cnt=0;
        for(int i=0;i<n-2;i++)
        {
            int greater=arr[i];
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                if(arr[l]+arr[r]>greater)
                {
                    cnt+=r-l;
                    l++;
                }
                else
                r--;
            }
        }
        
        return cnt;
    }
};