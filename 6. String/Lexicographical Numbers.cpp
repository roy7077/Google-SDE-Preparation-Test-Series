class Solution{
   public:

    void dfs(vector<int>& ans,int num,int& n)
    {
        //base case
        if(num>n)
        return ;
        
        ans.push_back(num);
        dfs(ans,num*10,n);
        
        if(num%10!=9)
        dfs(ans,num+1,n);
    }
	vector<int> lexicalOrder(int N)
	{
	    vector<int> ans;
	    dfs(ans,1,N);
	    
	    return ans;
	}
};