// Moore’s Voting Algorithm for n/3
class Solution {
  public:
    int repeatNum(int arr[] ,int n) {
        
        int e1=-1e9;
        int e2=-1e9;
        int cnt1=0;
        int cnt2=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==e1)
            cnt1++;
            else if(arr[i]==e2)
            cnt2++;
            else if(cnt1==0)
            {
                cnt1=1;
                e1=arr[i];
            }
            else if(cnt2==0)
            {
                cnt2=1;
                e2=arr[i];
            }
            else 
            {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1=cnt2=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==e1)
            cnt1++;
            else if(arr[i]==e2)
            cnt2++;
        }
        
        if(cnt1>(n/3) and cnt2>(n/3))
        return min(e1,e2);
        
        if(cnt1>(n/3))
        return e1;
        else if(cnt2>(n/3))
        return e2;
        
        return -1;
    }
};