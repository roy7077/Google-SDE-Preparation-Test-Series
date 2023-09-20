class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        int count=0;
        vector<int>mp(26,0);
        for(int i=0;i<p.size();i++){
          if(mp[p[i]-'a']==0){
            
              count++;
          }
            mp[p[i]-'a']++;
        }
        
        int i=0,j=0;
        int mini=INT_MAX,start=0,end=0;
        while(j<s.size()){
            mp[s[j]-'a']--;
            if(mp[s[j]-'a']==0) count--;
            while(count==0){
                if(j-i+1<mini){
                      mini=min(j-i+1,mini);
                    start=i;
                    end=j;
                }
              

                    mp[s[i]-'a']++;
                     if(mp[s[i]-'a']==1) count++;
               
              i++;
            }
            j++;
        }
        if(mini!=INT_MAX){
            return s.substr(start,mini);
        }
        else 
            return "-1";
        // int start=0;
        // int e=0;
        // int len=1e9;
        
        // unordered_map<char,int> mp1;
        // unordered_map<char,int> mp2;
        
        // for(auto it:p)
        // mp1[it]++;
        
        // //cout<<mp1.size()<<endl;
        // int i=0;
        // int j=0;
        // while(j<s.length())
        // {
        //     int si=j;
        //     while(j<s.length())
        //     {
        //         if(mp2.size()==mp1.size())
        //         break;
                
        //         if(mp1.count(s[j]))
        //         mp2[s[j]]++;
                
        //         j++;
        //     }
            
        //     //cout<<mp1.size()<<endl;
        //     //cout<<mp2.size()<<endl;
            
        //     while(i<j and mp2.size()==mp1.size())
        //     {
        //         if(j-i<len)
        //         {
        //             //cout<<"i -> "<<i<<" j -> "<<j<<endl;
        //             len=j-i;
        //             start=i;
        //             e=j-1;
        //         }
                
        //         if(mp1.count(s[i]))
        //         mp2[s[i]]--;
                
        //         if(mp2[s[i]]==0)
        //         mp2.erase(s[i]);
                
        //         i++;
        //     }
        // }
        
        // if(len>=1e9)
        // return "-1";
        
        // string ans="";
        // for(int j=start;j<=e;j++)
        // ans+=s[j];
        
        // return ans;
    }
};