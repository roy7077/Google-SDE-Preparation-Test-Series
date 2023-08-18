class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int n, int k){
        priority_queue <int, vector<int>, greater<int>> pq;
        for(int i=0;i<=k;i++)
        pq.push(arr[i]);
        
        vector<int> ans;
        for(int i=k+1;i<n;i++)
        {
            ans.push_back(pq.top());
            pq.pop();
            pq.push(arr[i]);
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};