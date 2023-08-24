class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    {
        int ele=-1e9;
        int cnt=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]==ele)
            cnt++;
            else
            cnt--;
            
            if(cnt<0)
            {
                ele=a[i];
                cnt=1;
            }
        }
        
        cnt=0;
        for(int i=0;i<size;i++)
        {
            if(a[i]==ele)
            cnt++;
        }
        
        if(cnt>(size/2))
        return ele;
        else
        return -1;
    }
};