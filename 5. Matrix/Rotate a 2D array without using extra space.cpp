class Solution{
public:	
	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    
	    // transpose of matrix...
        for(int i = 0;i< n; i++)
        {
           for(int j = i+1; j<n ; j++)
           {
               swap(arr[i][j] , arr[j][i]);
           }
        }
    
        // reverse the matrix by row wise...
        reverse(begin(arr), end(arr));
  } 

};