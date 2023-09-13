class Solution{
    public:
    bool checkAnagram(string S1, string S2)
    {
        if(S1.length()>S2.length())
        return 0;
        
        unordered_map<char,int> mp1;
        for(auto it:S1)
        mp1[it]++;
        
        int i=0;
        int j=S1.length()-1;
        
        while(j<S2.length())
        {
            unordered_map<char,int> mp2;
            for(int k=i;k<=j;k++)
            mp2[S2[k]]++;
            
            bool flag=1;
            
            if(mp1.size()!=mp2.size())
            flag=0;
            else
            {
                for(auto it:S1)
                {
                    if(mp1[it]!=mp2[it])
                    {
                        flag=0;
                        break;
                    }
                }
            }
            
            if(flag)
            return 1;
            
            i++;
            j++;
        }
        
        return 0;
    }
};