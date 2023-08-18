//Time  complexity - O(N*logN)
//Space complexity - O(N)
#define ll long long
class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        
        unordered_map<int,int> mp;
        int cnt=0;
        ll sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
            cnt++;
            
            if(mp.count(sum))
            cnt+=mp[sum];
            
            mp[sum]++;
        }
        
        return cnt;
    }
};