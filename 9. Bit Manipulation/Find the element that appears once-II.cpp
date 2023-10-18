// 😎 ALL FOUR APPROACHES 🔥


// MAPING | T - O(N) | S - O(N)
class Solution{
    public:	
	int search(int A[], int N){
	    
	    unordered_map<int,int> mp;
	    for(int i=0;i<N;i++)
	    mp[A[i]]++;
	    
	    for(auto it:mp)
	    {
	        if(it.second==1)
	        return it.first;
	    }
	    
	    return -1;
	}
};


// SORTING | T - O(NlogN) | S - O(1)
class Solution{
    public:	
	int search(int A[], int N){
	    
	    sort(A,A+N);
	    int i=0;
	    bool flag=0;
	    while(i<N-1)
	    {
	        if(A[i]!=A[i+1])
	        {
	            if((i+1)==N-1)
	            return A[N-1];
	            
	            if(A[i+2]!=A[i+1])
	            return A[i+1];
	        }
	        
	        i++;
	    }
	    
	    return A[N-1];
	}
};


// BINARY / DIVISIBLE BY 3 | T - O(31*N) | S - O(1)
class Solution{
    public:	
	int search(int A[], int N){
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


// XOR | T - O(N) | S - O(1)
class Solution{
    public:	
	int search(int A[], int N){
	    int one = 0;
	    int two = 0;
	    for(int i=0; i<N; i++) {
	        one = ((A[i] ^ one) & (~two));
	        two = ((A[i] ^ two) & (~one));
	    }
	    return one;
	}
};