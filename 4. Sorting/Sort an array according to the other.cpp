// Time complexity  - O(N*logN)
// Space complexity -O(N)
class Solution{
    public:
    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        unordered_map<int,int> mp;
        for(auto it:A1)
        mp[it]++;
        
        int i=0;
        for(auto it:A2)
        {
            while(mp[it]>=1)
            {
                A1[i]=it;
                mp[it]--;
                i++;
            }
        }
        
        int s=i;
        for(auto it:mp)
        {
            while(mp[it.first])
            {
                A1[i]=it.first;
                mp[it.first]--;
                i++;
            }
        }
        
        sort(A1.begin()+s,A1.end());
        return A1;
    } 
};