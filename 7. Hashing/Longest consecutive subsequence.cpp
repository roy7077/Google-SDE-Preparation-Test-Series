BRUTE FORCE

//Time complexity  - O(N*logN)
//Space complexity - O(1)
class Solution{
    public:
    int findLongestConseqSubseq(int arr[], int N)
    {
      int maxi=1;
      int cnt=1;
      for(int i=1;i<N;i++)
      {
          if(arr[i]==arr[i-1] )
          continue;
          
          if(arr[i-1]==arr[i]-1)
          cnt++;
          else
          {
              maxi=max(cnt,maxi);
              cnt=1;
          }
          maxi=max(cnt,maxi);
      }
      
      maxi=max(cnt,maxi);
      return maxi;
    }
};

// OPTIMIZED APPROACH

// //Time complexity  - O(N)
// //Space complexity - O(N)
// class Solution{
//     public:
//     int findLongestConseqSubseq(int arr[], int N)
//     {
//       int mp[1000000]={0};
//       int maxi=-1e9;
//       int mini=1e9;
      
//       for(int i=0;i<N;i++)
//       {
//           mp[arr[i]]=1;
//           mini=min(arr[i],mini);
//           maxi=max(arr[i],maxi);
//       }
      
//       int ans=0;
//       int cnt=0;
      
//       for(int i=mini;i<=maxi;i++)
//       {
//           if(mp[i]==0)
//           {
//               ans=max(cnt,ans);
//               cnt=0;
//           }
//           else
//           cnt++;
//       }
//       ans=max(cnt,ans);
//       return ans;
//     }
// };