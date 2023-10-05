// Time complexity - O(N)
// Space complexity- O(26)
class Solution{
    public:
    int longestKSubstr(string s, int k) {
        
        int mp[26]={0};
        int dist=0;
        int i=0;
        int j=0;
        int maxi=-1;
        
        while(j<s.length())
        {
            if(mp[s[j]-'a']==0)
            dist++;
            
            mp[s[j]-'a']++;
            
            while(dist>k)
            {
                mp[s[i]-'a']--;
                
                if(mp[s[i]-'a']==0)
                dist--;
                i++;
            }
            
            if(dist==k)
            maxi=max(maxi,j-i+1);
            j++;
        }
        
        return maxi;
    }
};