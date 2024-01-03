// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> st;
        for(auto it:asteroids)
        {
            bool flag=1;
            while(!st.empty() and st.top()>0 and it<0)
            {
                int top=st.top();
                st.pop();
                
                if(top==(it*-1))
                {
                    flag=0;
                    break;
                }
                else if(top>(it*-1))
                {
                    flag=0;
                    st.push(top);
                    break;
                }
            }
            
            if(flag)
            st.push(it);
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
