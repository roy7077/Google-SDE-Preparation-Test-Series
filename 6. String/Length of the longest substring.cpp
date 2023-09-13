class Solution{
    public:
    int longestUniqueSubsttr(string S){
        
        int freq[27]={0};
        int n=S.length();
        int i=0;
        int j=0;
        int ans=0;
        
        while(i<n and j<n)
        {
            if(freq[S[j]-'a']>=1)
            {
                while(freq[S[j]-'a']>=1)
                {
                    freq[S[i]-'a']--;
                    i++;
                }
            }
            
            freq[S[j]-'a']++;
            ans=max(ans,j-i+1);
            j++;
        }
        
        return ans;
    }
};
