class Solution {
    public:
    int totalFruits(vector<int> &A, int N) {
        
        unordered_map<int,int> mp;
        int cnt=0;
        int maxi=0;
        int i=0;
        int j=0;
        
        while(j<N)
        {
            mp[A[j]]++;
            while(mp.size()>2)
            {
                mp[A[i]]--;
                if(mp[A[i]]==0)
                mp.erase(A[i]);
                
                i++;
            }
            
            maxi=max(maxi,j-i+1);
            j++;
        }
        
        return maxi;
    }
};
