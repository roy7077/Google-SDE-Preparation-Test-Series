// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    vector<int> asteroidCollision(int N, vector<int> &A) {
        stack<int> st;
        for(auto it:A)
        {
            if(st.empty())
            st.push(it);
            else
            {
                if(it>0)
                st.push(it);
                else
                {
                    while(!st.empty() and st.top()>0 and st.top()<abs(it))
                    {
                        st.pop();
                    }
                    
                    if(!st.empty() and st.top()==abs(it))
                    {
                        st.pop();
                        continue;
                    }
                    
                    if(!st.empty() and st.top()>abs(it))
                    continue;
                    
                    st.push(it);
                }
            }
        }
        
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
