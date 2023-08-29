class Solution{
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        multiset<pair<double,pair<int,int>>> st;
        for(auto it:points)
        {
            int x=it[0];
            int y=it[1];
            
            double root=sqrt((x*x)+(y*y));
            st.insert({root,{x,y}});
        }
        
        vector<vector<int>> ans;
        for(auto it:st)
        {
            if(K==0)
            break;
            
            ans.push_back({it.second.first,it.second.second});
            K--;
        }
        
        return ans;
    }
};