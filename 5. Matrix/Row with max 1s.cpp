//Time complexity - O(N+M)
//Space Complexity- O(1)
class Solution{
    public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    
	    int j=m-1;
	    int i=0;
	    int row=-1;
	    while(j>=0 and i<n)
	    {
	        if(arr[i][j]==1)
	        {
	            j--;
	            row=i;
	        }
	        else
	        {
	            i++;
	        }
	    }
	    
	    return row;
	}

};