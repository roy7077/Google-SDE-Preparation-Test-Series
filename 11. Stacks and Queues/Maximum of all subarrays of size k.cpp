// Time complexity - O(NlogN)
// Space complexity- O(N)
// 1st -> number
// 2nd -> index
typedef pair<int,int> pi;
class Solution
{
    public:
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<pi> pq;
        for(int i=0;i<k-1;i++)
        pq.push({arr[i],i});
        
        vector<int> ans;
        int i=0;
        int j=k-1;
        while(j<n)
        {
           while(!pq.empty() and pq.top().second<i) 
           pq.pop();
          
           pq.push({arr[j],j});
           ans.push_back(pq.top().first);
           i++;
           j++;
        }
        
        return ans;
    }
};

/*
 this one is correct approach
*/
