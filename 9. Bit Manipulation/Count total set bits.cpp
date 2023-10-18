// ALL THREE APPROACHES

// 1st binary
//Time complexity - O(NlogN)
//Space complexity- O(1)
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int getBits(int x) 
    {
        int cnt=0;
        while(x)
        {
            if(x&1)
            cnt++;
            
            x/=2;
        }
        return cnt;
    }
    int countSetBits(int n)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        cnt+=getBits(i);
        
        return cnt;
    }
};

// 2nd DP
int countSetBits(int n)
    {
        vector<int> res(n + 1, 0);
        for (int x = 1; x <= n; x++)
            res[x] = res[x / 2] + (x % 2);
        
        int cnt=0;
        for(auto it:res)
        cnt+=it;
        
        return cnt;
    }
    
// 3rd log
//Time complexity - O(logN)
class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {   
       if((n&(n-1)) == 0){
       		//if n is power of 2 directly return result
           return 1+ log2(n)*(n/2);
       }else{
           // y is 2th power  before n
           int y = pow(2,(int)log2(n));
           return (n-y) + countSetBits(y)+ countSetBits(n-y);
       }
        
    }
};