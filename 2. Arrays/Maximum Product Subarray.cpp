//Time  complexity - O(N)
//Space complexity - O(1)
#define ll long long
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	   
	   ll sum=1;
	   ll maxi=-1e9;
	   
	   //left to right
	   for(int i=0;i<n;i++)
	   {
	       sum*=arr[i];
	       maxi=max(sum,maxi);
	       if(sum==0)
	       sum=1;
	   }
	   
	   //right to left
	   sum=1;
	   for(int i=n-1;i>=0;i--)
	   {
	       sum*=arr[i];
	       maxi=max(sum,maxi);
	       if(sum==0)
	       sum=1;
	   }
	   
	   return maxi;
	}
};