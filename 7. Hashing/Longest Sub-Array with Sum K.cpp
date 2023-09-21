// Time  complexity - O(N)
// Space complexity - O(N)
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        int len=0;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum==k)
            len=max(i+1,len);
            else if(mp.count(sum-k))
            len=max(i-mp[sum-k],len);
            
            if(mp.count(sum)==0)
            mp[sum]=i;
        }
        
        return len;
    } 

};