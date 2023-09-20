class Solution {
    public:
    string nextClosestTime(string time) {
        
        vector<char> v;
        for(auto it:time)
        {
            if(it!=':')
            v.push_back(it);
        }
        
        sort(v.begin(),v.end());
        
        //first case - replace last index
        for(auto it:v)
        {
            if(it>time[4])
            {
                time[4]=it;
                return time;
            }
        }
        
        //second case - replace both last and 2nd last index
        for(auto it:v)
        {
            if(it>time[3] and it<='5')
            {
                time[3]=it;
                time[4]=v[0];
                return time;
            }
        }
        
        //third case - 2nd , third and fourth
        for(auto it:v)
        {
            string temp="";
            temp+=(time[0]);
            temp+=(it);
            
            if(it>time[1] and temp<="23")
            {
                time[1]=it;
                time[3]=v[0];
                time[4]=v[0];
                return time;
            }
        }
        
        if(time[0]=='2' and time[1]=='3')
        {
            time[0]=time[1]=time[3]=time[4]='2';
            return time;
        }
        
        //fourth case - 
        for(auto it:v)
        {
            char temp=it;
            if(it>time[0] and it<='2')
            {
                time[0]=it;
                time[1]=v[0];
                time[3]=v[0];
                time[4]=v[0];
                return time;
            }
        }
        
        time[0]=v[0];
        time[1]=v[0];
        time[3]=v[0];
        time[4]=v[0];
        
        return time;
    }
};