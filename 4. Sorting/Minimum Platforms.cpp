// Time complexity  - O(N)
// Space complexity - O(N)
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	
    	int freq[2361]={0};
    	for(int i=0;i<n;i++)
    	{
    	    freq[arr[i]]++;
    	    freq[dep[i]+1]--;
    	}
    	
    	int maxi=0;
    	for(int i=0;i<2361;i++)
    	{
    	    freq[i]+=freq[i-1];
    	    maxi=max(freq[i],maxi);
    	}
    	
    	return maxi;
    }
};