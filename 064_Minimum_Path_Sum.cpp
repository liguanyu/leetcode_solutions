class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        int m = grid[0].size();
        int n = grid.size();
        
        vector<int> dp(m*n, 0);
        dp[0] = grid[0][0];
        
        for(int i=1; i<m; i++)
            dp[i] = dp[i-1] + grid[0][i]; 
        
        for(int j=1; j<n; j++)
            dp[j*m] = dp[j*m-m] + grid[j][0];
        
        for(int j=1; j<n; j++)
            for(int i=1; i<m; i++){
                dp[j*m + i] = dp[j*m + i-1] < dp[j*m-m + i] ? dp[j*m + i-1] : dp[j*m-m + i];
                dp[j*m + i] += grid[j][i];
            }
        
        return dp[n*m-1];
    }
};