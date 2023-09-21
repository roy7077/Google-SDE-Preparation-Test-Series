class Solution{
    public:
    int findSubArraySum(int A[], int N, int k)
    {
        unordered_map<int,int> mp;
        int sum=0;
        int cnt=0;
        mp[0]=1;
        
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(mp.count(sum-k))
            cnt+=mp[sum-k];
            
            mp[sum]++;
        }
        
        return cnt;
    }
};