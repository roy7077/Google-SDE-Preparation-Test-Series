//Time  complexity - O(N)
//Space complexity - O(N+1)
class Solution {
public:
    vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int> nI) {
        //Code Here
        vector<vector<int>>res;
        int i=0,n=intervals.size();
        
        //1st phase -> no overlapping
        while(i<n && intervals[i][1]<nI[0])
        {
            res.push_back(intervals[i]);
            i++;
        }
        
        //2nd phase -> overlapping
        while(i<n && intervals[i][0]<=nI[1])
        {
            nI[0]=min(nI[0],intervals[i][0]);
            nI[1]=max(nI[1],intervals[i][1]);
            i++;
        }
        
        res.push_back(nI);
        
        //3rd phase -> after overlapping
        while(i<n)
        {
            res.push_back(intervals[i]);
            i++;
        }
        
        return res;
    }
};