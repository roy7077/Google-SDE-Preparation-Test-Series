class Solution{   
    public:
    string solve(int arr[], int n) {
        
        sort(arr,arr+n);
        string s1="";
        string s2="";
        
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            if(i&1)
            s1+=char(arr[i]+48);
            else
            s2+=char(arr[i]+48);
            
            flag=(!flag);
        }
        
        string ans="";
        int i=s1.length()-1;
        int j=s2.length()-1;
        int c=0;
        
        while(i>=0 and j>=0)
        {
            int sum=(s1[i]-'0')+(s2[j]-'0')+c;
            ans=char((sum%10)+48)+ans;
            c=sum/10;
            
            i--;
            j--;
        }
        
        while(i>=0)
        {
            int sum=c+(s1[i]-'0');
            ans=char((sum%10)+48)+ans;
            c=sum/10;
            i--;
        }
        
        while(j>=0)
        {
            int sum=c+(s2[j]-'0');
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
