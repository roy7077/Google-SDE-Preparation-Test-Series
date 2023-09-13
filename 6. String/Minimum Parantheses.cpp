// STACK | T - O(N)  | S - O(N)
// Method - 1
class Solution{
    public:
	int MinParentheses(string S)
	{
	     stack<char> st;
	     int cnt=0;
	     
	     for(auto it:S)
	     {
	         if(it=='(')
	         st.push(it);
	         else
	         {
	             if(!st.empty() and st.top()=='(')
	             st.pop();
	             else
	             cnt++;
	         }
	     }
	     
	     cnt+=st.size();
	     return cnt;
	}
};
 
// OPTIMIZED | T - O(N)  | S - O(1)
// Method - 2
class Solution{
    public:
	int MinParentheses(string S)
	{
	     int cnt=0;
	     int ans=0;
	     for(auto it:S)
	     {
	         if(it=='(')
	         cnt++;
	         else
	         cnt--;
	         
	         if(cnt==-1)
	         {
	             cnt=0;
	             ans++;
	         }
	     }
	     
	     return cnt+ans;
	}
};