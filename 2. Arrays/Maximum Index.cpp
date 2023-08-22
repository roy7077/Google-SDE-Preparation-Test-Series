//Time complexity  - O(N)
//Space complexity - O(N)
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int A[], int N) 
    { 
        stack<int> st;
        for(int i=N-1;i>=0;i--)
        {
            if(st.empty() or A[i]>A[st.top()])
            st.push(i);
        }
        
        int ans=0;
        int i=0;
        while(i<N and !st.empty())
        {
            if(A[i]<=A[st.top()] and i<=st.top())
            {
                ans=max(ans,st.top()-i);
                st.pop();
            }
            else if(i>st.top())
            st.pop();
            else
            i++;
        }
        
        return ans;
    }
};