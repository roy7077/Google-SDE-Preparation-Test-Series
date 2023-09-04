// Time complexity - O(N)
// Space complexity- O(N+N)
class Solution{
    public:
    string decodedString(string s){
        
       string ans="";
       int i=s.length()-1;
       stack<string> st;
       string temp="";
       while(i>=0)
       {
           if(s[i]==']')
           {
               if(temp.length()>0)
               {
                   st.push(temp);
                   temp="";
               }
               st.push("]");
           }
           else if(s[i]>='a' and s[i]<='z')
           temp=s[i]+temp;
           else if(s[i]=='[')
           {
               st.push(temp);
               temp="";
           }
           else
           {
               string temp1="";
               while(!st.empty() and st.top()!="]")
               {
                  temp1+=st.top();
                  st.pop();
               }
               st.pop();

               int num=0;
               int ten=1;
               while(i>=0 and (s[i]>='0' and s[i]<='9'))
               {
                   num+=(s[i]-'0')*ten;
                   ten*=10;
                   i--;
               }
               
               i++;
               int n=num;
               while(n--)
               {
                   temp+=temp1;
               }
              
               st.push(temp);
               temp="";
           }
           
           i--;
       }
       
       
       if(st.empty())
       return  "";
       else
       {
           while(!st.empty())
           {
               ans+=st.top();
               st.pop();
           }
           
           return ans;
       }
    }
};