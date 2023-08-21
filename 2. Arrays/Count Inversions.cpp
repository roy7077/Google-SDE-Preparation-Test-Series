#define ll long long
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll merge(ll* a,ll s,ll mid,ll e)
    {
        ll i=s;
        ll j=mid+1;
        ll cnt=0;
        vector<ll> v;
        while(i<=mid and j<=e)
        {
            if(a[i]<=a[j])
            {
                v.push_back(a[i]);
                i++;
            }
            else
            {
                cnt+=(mid-i+1);
                v.push_back(a[j]);
                j++;
            }
        }
        
        while(i<=mid)
        {
            v.push_back(a[i]);
            i++;
        }
        
        while(j<=e)
        {
            v.push_back(a[j]);
            j++;
        }
        
        ll k=s;
        for(auto it:v)
        {
            a[k]=it;
            k++;
        }
        
        return cnt;
    }
    
    ll help(ll* A,ll s,ll e)
    {
        if(s>=e)
        return 0;
        
        ll mid=(s+e)/2;
        ll c1=help(A,s,mid);
        ll c2=help(A,mid+1,e);
        ll c3=merge(A,s,mid,e);
        
        return c1+c2+c3;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return help(arr,0,N-1);
    }

};