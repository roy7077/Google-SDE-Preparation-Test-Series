class Solution{
     public:
     bool check(string s, string w) 
     {
        int m = s.size();
        int n = w.size();
        int i = 0;
        int j = 0;
        
        for(int i2=0,j2=0; i<m && j<n; i=i2, j=j2) 
        {
            if (s[i] != w[j]) 
            return false;
            
            while(i2 < m && s[i2] == s[i]) 
            i2++;
            
            while(j2 < n && w[j2] == w[j]) 
            j2++;
            
            if ((i2 - i) != (j2 - j) && (i2 - i) < max(3, j2 - j)) 
            return false; 
        }
        return i == m && j == n;
    }
    
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (auto& word:words) {
            if (check(s, word)) ans++;
        }
        return ans;
    }
 };