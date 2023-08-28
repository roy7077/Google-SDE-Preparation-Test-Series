class Solution {
    public:
    long long solve(vector<int> &arr, int n, long long k){
        long long sum = 0;
        long long ans = 0;
        int i = 0;
        int j = 0;
        
        while(j < n){
            sum += arr[j];
            while(sum > k){
                sum -= arr[i];
                i++;
            }
            
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        return solve(A, N, R) - solve(A, N, L-1);
    }
};