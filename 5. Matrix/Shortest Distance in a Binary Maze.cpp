// Time complexity  - O(N*M*4)
// Space complexity - O(2*N*M)
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{source.first,source.second}});
        
        int dr[4]= {-1,1,0,0};
        int dc[4]={0,0,-1,1};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            int x=it.second.first;
            int y=it.second.second;
            int s=it.first;
            
            if(x==destination.first and y==destination.second)
            return s;
            
            for(int i=0;i<4;i++)
            {
                int delrow=x+dr[i];
                int delcol=y+dc[i];
                
                if(delrow>=0 and delrow<n and delcol>=0 and delcol<m
                 and visited[delrow][delcol]==0 and grid[delrow][delcol]==1)
                 {
                    visited[delrow][delcol]=1;
                    q.push({s+1,{delrow,delcol}});
                 }
            }
        }
        
        return -1;
    }
};