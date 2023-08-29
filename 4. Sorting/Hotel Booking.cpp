class Solution {
    public:
	bool areBookingsPossible(int K, vector<int>&arrival, vector<int>&departure){
	    
	    int freq[100002]={0};
	    int n=arrival.size();
	    
	    for(int i=0;i<n;i++)
	    {
	        freq[arrival[i]]++;
	        freq[departure[i]]--;
	    }
	    
	    int maxi=freq[0];
	    for(int i=1;i<100002;i++)
	    {
	        freq[i]+=freq[i-1];
	        maxi=max(maxi,freq[i]);
	    }
	    
	    if(K>=maxi)
	    return 1;
	    else
	    return 0;
    }
};