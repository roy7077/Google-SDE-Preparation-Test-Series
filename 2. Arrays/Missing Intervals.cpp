// T - O(N) 
// S - O(N)
class Solution {
  public:
    vector<int> printMissingIntervals(int a[], int n) {
        vector<int> ans;
        int start=-1;
        int end=-1;
        int j=0;
        for(int i=0;i<=99999;i++)
        {
            if(a[j]!=i)
            {
                if(start==-1)
                start=i;
            }
            else
            {
                if(start!=-1)
                {
                    ans.push_back(start);
                    ans.push_back(i-1);
                    start=-1;
                }
                j++;
            }
        }
        
        if(start!=-1)
        {
            ans.push_back(start);
            ans.push_back(99999);
        }
        
        return ans;
    }
};