// Time complexity - O(N)
// Space complexity- O(N)
int countRev (string s)
{
    stack<char> st;
    int cnt=0;
    for(auto it:s)
    {
        if(it=='{')
        st.push(it);
        else
        {
            if(st.empty())
            {
                cnt++;
                st.push('{');
            }
            else
            st.pop();
        }
    }
    
    if(st.size()&1)
    return -1;
    
    cnt+=(st.size())/2;
    return cnt;
}