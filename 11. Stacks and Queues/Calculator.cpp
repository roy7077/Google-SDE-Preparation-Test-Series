// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int eval(string s) {
        stack<int> st;
        char op='+';
        int num=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            int ch=s[i];
            if(ch>='0' and ch<='9')
            {
                num*=10;
                num+=(ch-'0');
            }
            
            if(ch=='+' or ch=='-' or ch=='*' or ch=='/' or i==n-1)
            {
                if(op=='+')
                st.push(num);
                else if(op=='-')
                st.push(-1*num);
                else if(op=='*')
                {
                    int temp=st.top();
                    st.pop();
                    st.push(temp*num);
                }
                else
                {
                    int temp=st.top();
                    st.pop();
                    st.push(temp/num);
                }
                num=0;
                op=ch;
            }
        }
        int ans=0;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};