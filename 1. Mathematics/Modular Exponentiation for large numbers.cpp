#define ll long long
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    ll ans=1;
		    while(n)
		    {
		        if(n&1)
		        {
		            n--;
		            ans=(ans*x)%M;
		        }
		        else
		        {
		            x=(x*x)%M;
		            n/=2;
		        }
		    }
		    
		    return ans;
		}
};
