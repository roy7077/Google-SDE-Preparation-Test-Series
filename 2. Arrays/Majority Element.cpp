class Solution{
  public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int size)
    {
        int cnt=1;
        int ind=0;
        
        for(int i=1;i<size;i++)
        {
            if(arr[i]==arr[ind])
            cnt++;
            else
            cnt--;
            
            if(cnt<0)
            {
                cnt=1;
                ind=i;
            }
        }
        
        cnt=0;
        for(int i=0;i<size;i++)
        {
            if(arr[i]==arr[ind])
            cnt++;
        }
        
        if(cnt>(size/2))
        return arr[ind];
        else
        return -1;
    }
};