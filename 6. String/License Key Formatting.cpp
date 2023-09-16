// Time Complexity  - O(N)
// Space Complexity - O(N)
class Solution
{
   public:
    string ReFormatString(string S, int k){
    
        int cnt=0;
        for(auto it:S)
        {
            if(it!='-')
            cnt++;
        }
    	
    	int first=cnt%k;
    	string ans="";
    	
    	int i=0;
    	int count=0;
    	while(i<S.length() and count<first)
    	{
    	    if(S[i]!='-')
    	    {
    	        if(S[i]>='a' and S[i]<='z')
    	        ans+=char(int(S[i])-32);
    	        else
    	        ans+=S[i];
    	        
    	        count++;
    	    }
    	    
    	    i++;
    	}
    	
    	while(first and i<S.length())
    	{
    	    if(S[i]!='-')
    	    {
    	        ans+='-';
    	        break;
    	    }
    	    
    	    i++;
    	}
    	
        count=0;
        while(i<S.length())
        {
            if(count==k and S[i]!='-')
            {
                ans+='-';
                count=0;
            }
            
            if(S[i]!='-')
            {
                if(S[i]>='a' and S[i]<='z')
    	        ans+=char(int(S[i])-32);
    	        else
    	        ans+=S[i];
    	        
    	        count++;
            }
            
            i++;
        }
        
        return ans;
    }
};
