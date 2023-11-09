// Time complexity - O(N)
// Space complexity- O(N)
int countRev (string s)
{
    if(s.length()&1)
    return -1;
    
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
                st.push('{');
                cnt++;
            }
            else
            st.pop();
        }
    }
    
    cnt+=st.size()/2;
    return cnt;
}