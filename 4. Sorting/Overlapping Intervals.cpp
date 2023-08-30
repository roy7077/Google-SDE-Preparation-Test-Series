// Time complexity  - O(N*logN)
// Space complexity - O(N); 
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
        
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0];
        int e=intervals[0][1];
        
        vector<vector<int>> ans;
        for(int i=1;i<n;i++)
        {
            if(e<intervals[i][0])
            {
                ans.push_back({s,e});
                s=intervals[i][0];
            }
            
            e=max(intervals[i][1],e);
        }
        ans.push_back({s,e});
        return ans;
    }
};