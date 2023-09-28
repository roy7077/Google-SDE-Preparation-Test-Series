/*--------Josephus problem---------*/
// Time complexity - O(N*N)
// Space complexity- O(N)
class Solution {
    public:
    int help(vector<int>& v,int ind,int k)
    {
        //base case
        if(v.size()==1)
        return v[0];
        
        //recursive calls
        //small calculation
        ind=(ind+k)%v.size();
        v.erase(v.begin()+ind);
        int ans=help(v,ind,k);
        return ans;
    }
    int safePos(int n, int k) {
        
        vector<int> v;
        for(int i=1;i<=n;i++)
        v.push_back(i);
        
        return help(v,0,k-1);
    }
};