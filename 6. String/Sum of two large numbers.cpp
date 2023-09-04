// Time complexity  - O(N+M)
// Space complexity - O(max(N,M));
class Solution {
    public:
    string findSum(string X, string Y) {
        
        string ans="";
        int i=X.length()-1;
        int j=Y.length()-1;
        
        int c=0;
        while(i>=0 and j>=0)
        {
            int sum=(X[i]-'0')+(Y[j]-'0')+c;
            ans=char((sum%10)+48)+ans;
            c=sum/10;
            i--;
            j--;
        }
        
        while(i>=0)
        {
            int sum=(X[i]-'0')+c;
            ans=char((sum%10)+48)+ans;
            c=sum/10;
            i--;
        }
        
        while(j>=0)
        {
            int sum=(Y[j]-'0')+c;
            ans=char((sum%10)+48)+ans;
            c=sum/10;
            j--;
        }
        
        if(c)
        ans=char(c+48)+ans;
        
        for(int i=0;i<ans.length();i++)
        {
            if(ans[i]!='0')
            return ans.substr(i);
        }
        
        return "0";
    }
};