// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    string findHint(string S, string G) {
        
        int mp[11]={0};
        for(auto it:S)
        mp[it-'0']++;
        
        int bull=0;
        int cows=0;
        
        for(int i=0;i<G.length();i++)
        {
            if(S[i]==G[i])
            {
                bull++;
                mp[S[i]-'0']--;
            }
        }
        
        for(int i=0;i<G.length();i++)
        {
            if(S[i]!=G[i] and mp[G[i]-'0']>=1)
            {
                cows++;
                mp[G[i]-'0']--;
            }
        }
        
        return to_string(bull)+'A'+to_string(cows)+'B';
    }
};

