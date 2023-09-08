class Solution {
    public:
    
    bool canTransform(string S, string T) {
        
        if(S.length()!=T.length())
        return 0;
        
        vector<pair<char,int>> v1;
        vector<pair<char,int>> v2;
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='L')
            v1.push_back({'L',i});
            else if(S[i]=='R')
            v1.push_back({'R',i});
            
            if(T[i]=='L')
            v2.push_back({'L',i});
            else if(T[i]=='R')
            v2.push_back({'R',i});
        }
        
        if(v1.size()!=v2.size())
        return false;
        
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i].first!=v2[i].first)
            return false;
            
            if(v1[i].first=='L')
            {
                if(v1[i].second<v2[i].second)
                return false;
            }
            
            if(v2[i].first=='R')
            {
                if(v1[i].second>v2[i].second)
                return false;
            }
        }
        
        return true;
    }
};