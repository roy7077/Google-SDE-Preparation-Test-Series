#define ll long long
long long maxArea(long long A[], int len)
{
    ll i=0;
    ll j=len-1;
    ll maxi=0;
    
    while(i<j)
    {
        ll area=min(A[i],A[j])*(j-i);
        maxi=max(maxi,area);
        
        if(A[i]<A[j])
        i++;
        else
        j--;
    }
    
    return maxi;
}
