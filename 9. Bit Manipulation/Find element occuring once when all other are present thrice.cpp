class Solution {
  public:
    int singleElement(int A[] ,int N) {
        int ans=0;
	    for(int i=0;i<=31;i++)
	    {
	        int x=(1<<i);
	        int cnt=0;
	        for(int j=0;j<N;j++)
	        {
	            if(A[j]&x)
	            cnt++;
	        }
	        
	        if(cnt%3)
	        ans=ans | (1<<i);
	    }
	    
	    return ans;
    }
};
