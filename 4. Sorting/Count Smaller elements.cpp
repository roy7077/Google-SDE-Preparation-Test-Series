class Solution{
    
    public:	
    void inversion(vector<pair<int,int>>& v,vector<int>& count,int s,int e)
    {
        vector<pair<int,int>> temp;
        int mid=(s+e)/2;
        int i=s;
        int j=mid+1;
        
        while(i<=mid and j<=e)
        {
            if(v[i].second<=v[j].second)
            {
                temp.push_back(v[j]);
                j++;
            }
            else
            {
                count[v[i].first]+=e-j+1;
                temp.push_back(v[i]);
                i++;
            }
        }
        
        while(i<=mid)
        {
           temp.push_back(v[i]);
           i++;
        }
        
        while(j<=e)
        {
           temp.push_back(v[j]);
           j++;
        }
        
        int k=s;
        for(auto it:temp)
        {
            v[k]=it;
            k++;
        }
    }
    void help(vector<pair<int,int>>& v,vector<int>& count,int s,int e)
    {
        if(s>=e)
        return ;
        
        int mid=(s+e)/2;
        help(v,count,s,mid);
        help(v,count,mid+1,e);
        inversion(v,count,s,e);
        
        return ;
    }
	vector<int> constructLowerArray(int *arr, int n) {
	    
	    vector<pair<int,int>> v;
	    for(int i=0;i<n;i++)
	    v.push_back({i,arr[i]});
	    
	    vector<int> count(n,0);
	    help(v,count,0,n-1);
	    return count;
	}
};
