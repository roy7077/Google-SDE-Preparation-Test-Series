// Time  complexity - O(N)
// Space complexity - O(N)
class Solution {
  public:
  
    int minSwaps(int N,vector<int> A, vector<int> B){
        
        unordered_map<int,int> mp;
        for(int i=0;i<N;i++)
        {
            mp[A[i]]++;
            mp[B[i]]++;
        }
        
        int maxi=0;
        int ele=-1;
        for(auto it:mp)
        {
            if(it.second>maxi)
            {
                maxi=it.second;
                ele=it.first;
            }
        }
        
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<N;i++)
        {
            if(A[i]!=ele and B[i]!=ele)
            return -1;
            
            if(A[i]!=ele)
            cnt1++;
            else if(B[i]!=ele)
            cnt2++;
        }
        
        return min(cnt1,cnt2);
    }
};