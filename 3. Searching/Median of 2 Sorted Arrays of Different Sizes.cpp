#define ll long long
class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> temp;
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        
        while(i<n and j<m)
        {
            if(nums1[i]<nums2[j])
            {
                temp.push_back(nums1[i]);
                i++;
            }
            else
            {
                temp.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i<n)
        {
            temp.push_back(nums1[i]);
            i++;
        }
        
        while(j<m)
        {
            temp.push_back(nums2[j]);
            j++;
        }
        
        int nm=n+m;
        return nm%2?temp[nm/2]:(temp[nm/2]+temp[nm/2-1])/2.0;
    }
};
