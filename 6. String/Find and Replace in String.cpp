class Solution {
    public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        
        int n=Q;
        int cnt=0;
        string ans="";
        for(int i=0;i<n;i++)
        {
            int ind=index[i]+cnt;
            string temp=S.substr(ind,sources[i].length());
            if(temp==sources[i])
            {
                cnt+=targets[i].length()-sources[i].length();
                string first=S.substr(0,ind);
                string second=S.substr(ind+sources[i].length());
                ans+=first;
                ans+=targets[i];
                ans+=second;
                S=ans;
                ans="";
            }
        }
        
        return S;
    }
};