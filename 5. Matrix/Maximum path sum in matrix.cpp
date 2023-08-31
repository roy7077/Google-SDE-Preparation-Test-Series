😎 GET  ALL  FOUR  APPROACHES 😎
RECURSION

class Solution{
public:
    
    int help(vector<vector<int>>& Matrix,int i,int j)
    {
        //base case
        int n=Matrix.size();
        int m=Matrix[0].size();
        if(i<0 or i>n or j<0 or j>m)
        return 0;
        
        if(i==0)
        return Matrix[0][j];
        
        //recursive calls
        //small calculation
        
        int a,b,c;
        a=b=c=0;
        
        a=Matrix[i][j]+help(Matrix,i-1,j-1);
        b=Matrix[i][j]+help(Matrix,i-1,j);
        c=Matrix[i][j]+help(Matrix,i-1,j+1);
        
        return max({a,b,c});
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int maxi=0;
        for(int i=0;i<N;i++)
        {
            int ans=help(Matrix,N-1,i);
            maxi=max(ans,maxi);
        }
        
        return maxi;
    }
};
 

MEMOIZATION

class Solution{
public:
    
    int help(vector<vector<int>>& Matrix,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        int n=Matrix.size();
        int m=Matrix[0].size();
        if(i<0 or i>=n or j<0 or j>=m)
        return -1e9;
        
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        if(i==0)
        return Matrix[0][j];
        
        //recursive calls
        //small calculation
        
        int a,b,c;
        a=b=c=0;
        
        a=Matrix[i][j]+help(Matrix,i-1,j-1,memo);
        b=Matrix[i][j]+help(Matrix,i-1,j,memo);
        c=Matrix[i][j]+help(Matrix,i-1,j+1,memo);
        
        return memo[i][j]=max({a,b,c});
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int maxi=0;
        vector<vector<int>> memo(N,vector<int>(N,-1));
        for(int i=0;i<N;i++)
        {
            int ans=help(Matrix,N-1,i,memo);
            maxi=max(ans,maxi);
        }
        
        return maxi;
    }
};
 

TABULATION

//Time complexity  - O(N*N)
//Space complexity - O(N*N)
class Solution{
    public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp(N,vector<int>(N,0));
        for(int i=0;i<N;i++)
        dp[0][i]=Matrix[0][i];
        
        for(int i=1;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int a,b,c;
                a=b=c=0;
                
                if(i-1>=0 and j-1>=0)
                a=Matrix[i][j]+dp[i-1][j-1];
                
                if(i-1>=0)
                b=Matrix[i][j]+dp[i-1][j];
                
                if(i-1>=0 and j+1<N)
                c=Matrix[i][j]+dp[i-1][j+1];
                
                dp[i][j]=max({a,b,c});
            }
        }
        
        int maxi=0;
        for(int i=0;i<N;i++)
        maxi=max(maxi,dp[N-1][i]);
        
        return maxi;
    }
};
 

SPACE OPTIMIZED

//Time complexity  - O(N*N)
//Space complexity - O(N)
class Solution{
    public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<int> pre(N,0);
        for(int i=0;i<N;i++)
        pre[i]=Matrix[0][i];
        
        for(int i=1;i<N;i++)
        {
            vector<int> curr(N,0);
            for(int j=0;j<N;j++)
            {
                int a,b,c;
                a=b=c=0;
                
                if(i-1>=0 and j-1>=0)
                a=Matrix[i][j]+pre[j-1];
                
                if(i-1>=0)
                b=Matrix[i][j]+pre[j];
                
                if(i-1>=0 and j+1<N)
                c=Matrix[i][j]+pre[j+1];
                
                curr[j]=max({a,b,c});
            }
            
            pre=curr;
        }
        
        int maxi=0;
        for(int i=0;i<N;i++)
        maxi=max(maxi,pre[i]);
        
        return maxi;
    }
};