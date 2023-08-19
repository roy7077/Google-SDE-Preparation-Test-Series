//Time  complexity - O(N/2)
//Space complexity - O(1)
class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
        int i=0;
        int j=n-1;
        int k=0;
        int maxi=1e9;
        bool flag=0;
        while(i<=j)
        {
            if(flag)
            {
                arr[k]=((arr[i]%maxi)*maxi)+(arr[k]%maxi);
                i++;
                flag=(!flag);
            }
            else
            {
                arr[k]=((arr[j]%maxi)*maxi)+(arr[k]%maxi);
                j--;
                flag=(!flag);
            }
            k++;
        }
        
        for(int i=0;i<n;i++)
        arr[i]/=maxi;
        
    }
};
