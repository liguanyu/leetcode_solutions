class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0){
            return 0;
        }
        
        vector<int> dp(m*n, 0);
        
        for(int i=0; i<m; i++){
            dp[i] = 1;
        }
        
        for(int i=0; i<n; i++){
            dp[i*m] = 1;
        }
        
        for(int j=1; j<n; j++)
            for(int i=1; i<m; i++){
                dp[j*m + i] = dp[j*m + i - 1] + dp[j*m - m + i];
            }
        
        return dp[m*n - 1];
    }
};