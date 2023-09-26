class Solution
{
    public:
    int LengthOfLongestSubstringTwoDistinct(string S)
    {
    	unordered_map<char,int> mp;
    	int maxi=-1;
    	int cnt=0;
    	
    	int i=0;
    	int j=0;
    	while(j<S.length())
    	{
    	    mp[S[j]]++;
    	    cnt++;
    	    
    	    while(i<S.length() and mp.size()>2)
	        {
	            mp[S[i]]--;
	            if(mp[S[i]]==0)
	            mp.erase(S[i]);
	            
	            cnt--;
	            i++;
	        }
    	    
    	    maxi=max(cnt,maxi);
    	    j++;
    	}
    	
    	return maxi;
    }

};
