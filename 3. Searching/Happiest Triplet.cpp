/**
 *  a,b,c  max(a,b,c)-min(a,b,c) should be minimum
 *  that's mean diff should be minimum
 *  difference between max and min should be minimum
 *  two numbers should be closest
 */

class Solution
{
  public:
    vector<int> smallestDifferenceTriplet(int arr1[], int arr2[], int arr3[], int n)
    {
        sort(arr1,arr1+n);
        sort(arr2,arr2+n);
        sort(arr3,arr3+n);
        
        int i=0;
        int j=0;
        int k=0;
        
        int a,b,c;
        a=b=c=1e9;
        
        int ans=1e9;
        while(i<n and j<n and k<n)
        {
            int mini=min({arr1[i],arr2[j],arr3[k]});
            int maxi=max({arr1[i],arr2[j],arr3[k]});
            int sum=arr1[i]+arr2[j]+arr3[k];
            
            if((maxi-mini)<ans)
            {
                ans=maxi-mini;
                a=mini;
                c=maxi;
                b=sum-(mini+maxi);
            }
            
            if(mini==arr1[i])
            i++;
            else if(mini==arr2[j])
            j++;
            else
            k++;
        }
        
        return {c,b,a};
    }
};