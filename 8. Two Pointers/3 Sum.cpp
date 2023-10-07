class Solution {
    public:
    vector<vector<int>> findTriplets(vector<int> &A, int N) {
        
	    sort(A.begin(),A.end());
	    vector<vector<int>> ans;
        for(int i=0;i<N;i++)
        {
            int l=i+1;
            int h=N-1;
            
            while(l<h)
            {
                int temp=A[i]+A[l]+A[h];
                if(temp==0)
                {
                    ans.push_back({A[i],A[l],A[h]});
                    
                    while(l<h and A[l]==A[l+1])
                    {
                        l++;
                    }
                    l++;
                }
                else if(temp<0)
                {
                   while(l<h and A[l]==A[l+1])
                    {
                        l++;
                    }
                    l++; 
                }
                else
                {
                    while(h>l and A[h]==A[h-1])
                    {
                        h--;
                    }
                    h--; 
                }
            }
            
            while(i<N and A[i]==A[i+1])
            {
                i++;
            }
        }

        return ans;
    }
};