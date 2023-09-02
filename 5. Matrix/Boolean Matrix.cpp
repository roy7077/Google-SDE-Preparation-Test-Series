//Time complexity  - O(N*M)
//Space complexity - O(N+M)
class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int r=matrix.size();
        int c=matrix[0].size();
        
        vector<int> row(r,0);
        vector<int> col(c,0);
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j])
                {
                    col[j]=1;
                    row[i]=1;
                }
            }
        }
        
        //for column
        for(int i=0;i<c;i++)
        {
            if(col[i])
            {
                for(int j=0;j<r;j++)
                matrix[j][i]=1;
            }
        }
        
        //for row
        for(int i=0;i<r;i++)
        {
            if(row[i])
            {
                for(int j=0;j<c;j++)
                matrix[i][j]=1;
            }
        }
        
        return ;
    }
};
