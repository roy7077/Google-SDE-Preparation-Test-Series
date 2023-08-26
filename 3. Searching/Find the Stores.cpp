// Time complexity  - O(MlogM + N*2*log(M))
// Space complexity - O(N)

class Solution
{
    public:
    void lower(vector<int>& a,int x,int s,int e,int& ind)
    {
        //base case
        if(s>e)
        return ;
        
        //small calculation 
        //recursive call
        int mid=(s+e)/2;
        if(a[mid]==x)
        {
            ind=mid;
            return ;
        }
        
        if(a[mid]<x)
        {
            ind=mid;
            lower(a,x,mid+1,e,ind);
        }
        else
        lower(a,x,s,mid-1,ind);
    }
    
    void upper(vector<int>& a,int x,int s,int e,int& ind)
    {
        //base case
        if(s>e)
        return ;
        
        //small calculation 
        //recursive call
        int mid=(s+e)/2;
        if(a[mid]==x)
        {
            ind=mid;
            return ;
        }
        
        if(a[mid]>x)
        {
            ind=mid;
            upper(a,x,s,mid-1,ind);
        }
        else
        upper(a,x,mid+1,e,ind);
    }
    
    vector<int> findStores(int N, vector<int> houses, int M, vector<int> stores)
    {
        sort(stores.begin(),stores.end());
        vector<int> ans;
        for(auto it:houses)
        {
            int a=-1;
            int b=-1;
            
            lower(stores,it,0,M-1,a);
            upper(stores,it,0,M-1,b);
            
            //cout<<a<<" "<<b<<endl;
            
            if(a==-1 and b!=-1)
            ans.push_back(stores[b]);
            else if(a!=-1 and b==-1)
            ans.push_back(stores[a]);
            else
            {
                if((it-stores[a])==(stores[b]-it))
                {
                    ans.push_back(min(stores[a],stores[b]));
                }
                else if((it-stores[a])<(stores[b]-it))
                ans.push_back(stores[a]);
                else
                ans.push_back(stores[b]);
            }
            
        }
        
        return ans;
    }
};
