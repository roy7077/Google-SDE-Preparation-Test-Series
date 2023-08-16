/* convert it to base 9 */
#define ll long long
class Solution{
	public:
	
	long long findNth(long long N)
    {
        ll ans=0;
        ll p=1;
        
        while(N)
        {
            ll x=N%9;
            ans+=x*p;
            p*=10;
            N/=9;
        }
        
        return ans;
    }
};