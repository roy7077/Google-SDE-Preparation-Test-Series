class Solution
{
    public:
        #define ll long long
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            ll maxi=1e7;
            ll i=0;
            ll j=0;
            ll k=0;
            
            while(i<n and j<m)
            {
                ll a=arr1[i]%maxi;
                ll b=arr2[j]%maxi;
                
                if(a<b)
                {
                    if(k<n)
                    arr1[k]=a*maxi+(arr1[k]%maxi);
                    else
                    arr2[k-n]=a*maxi+(arr2[k-n]%maxi);
                    
                    i++;
                    
                }
                else
                {
                    if(k<n)
                    arr1[k]=b*maxi+(arr1[k]%maxi);
                    else
                    arr2[k-n]=b*maxi+(arr2[k-n]%maxi);
                    
                    j++;
                }
                k++;
            }
            
            //if any left in 1st array
            while(i<n)
            {
                if(k<n)
                arr1[k]=(arr1[i]%maxi)*maxi+(arr1[k]%maxi);
                else
                arr2[k-n]=(arr1[i]%maxi)*maxi+(arr2[k-n]%maxi);
                
                i++;
                k++;
            }
            
            //if any left in 2nd array
            while(j<m)
            {
                if(k<n)
                arr1[k]=(arr2[j]%maxi)*maxi+(arr1[k]%maxi);
                else
                arr2[k-n]=(arr2[j]%maxi)*maxi+(arr2[k-n]%maxi);
                
                j++;
                k++;
            }
            
            for(int k=0;k<n;k++)
            arr1[k]/=maxi;
            
            for(int l=0;l<m;l++)
            arr2[l]/=maxi;
            
        } 
};