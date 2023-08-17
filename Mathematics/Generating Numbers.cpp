#define ll long long
class Solution
{
    public:
    vector<long long> generateNumbers(int N)
    {
        vector<ll> ans;
        set<ll> s; //we can use priority queue as well
        
        if(N<1)
        return ans;
        
        s.insert(1);
        while(ans.size()<N)
        {
            ll num=*(s.begin());
            s.erase(num);
            ans.push_back(num);
            
            //Generating numbers
            s.insert(num*2);
            s.insert(num*3);
            s.insert(num*5);
            s.insert(num*7);
        }
        
        return ans;
    }
};