// Time complexity - O(N+M+K)
// Space complexity- O(1)
class Solution{
    public:
    int minimize(vector<int> &X, vector<int> &Y, vector<int> &Z) {
        
        int i=0;
        int j=0;
        int k=0;
        
        int mini=1e9;
        while(i<X.size() and j<Y.size() and k<Z.size())
        {
            int ans=max({abs(X[i]-Y[j]),abs(Y[j]-Z[k]),abs(Z[k]-X[i])});
            mini=min(ans,mini);
            
            if(X[i]<=Y[j] and X[i]<=Z[k])
            i++;
            else if(Y[j]<=X[i] and Y[j]<=Z[k])
            j++;
            else
            k++;
        }
        
        return mini;
    }