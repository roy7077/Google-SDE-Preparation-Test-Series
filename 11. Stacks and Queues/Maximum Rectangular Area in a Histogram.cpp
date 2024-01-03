#define ll long long
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        vector<ll> left_small(n,0);
        vector<ll> right_small(n,0);
        
        //finding left smaller
        stack<ll> st;
        for(ll i=0;i<n;i++)
        {
            while(!st.empty() and heights[st.top()]>=heights[i])
            st.pop();
            
            if(st.empty())
            left_small[i]=0;
            else
            left_small[i]=st.top()+1;
                
            st.push(i);
        }
        
        //calculation right smaller
        stack<ll> st2;
        for(ll i=n-1;i>=0;i--)
        {
            while(!st2.empty() and heights[st2.top()]>=heights[i])
            st2.pop();
            
            if(st2.empty())
            right_small[i]=n-1;
            else
            right_small[i]=st2.top()-1;
                
            st2.push(i);
        }
        
        //calculation maximum rectangle area
        ll maxi=0;
        for(int i=0;i<n;i++)
        {
            ll area=(right_small[i]-left_small[i]+1)*heights[i];
            maxi=max(maxi,area);
        }
        
        return maxi;
    }
};
