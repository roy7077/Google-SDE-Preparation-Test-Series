class Solution {
  public:
    
    int kadne(vector<int>& v)
    {
        int sum=0;
        int maxi=-1e9;
        
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];
            maxi=max(sum,maxi);
            
            if(sum<0)
            sum=0;
        }
        
        return maxi;
    }
    
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        
        int ans=-1e9;
        for(int i=0;i<C;i++)
        {
            vector<int> sum(R,0);
            for(int j=i;j<C;j++)
            {
                for(int K=0;K<R;K++)
                sum[K]+=M[K][j];
                
                int aa=kadne(sum);
                ans=max(ans,aa);
            }
        }
        
        return ans;
    }
};