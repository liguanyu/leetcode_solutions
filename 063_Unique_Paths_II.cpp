/*
I think it is confused that there can be a obstacle at the 
beginning and the end of the grid.
:-(
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0)
            return 0;
        
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        
        if(m == 0 || n == 0){
            return 0;
        }
        
        vector<long long> dp(m*n, 0);
        
        if(obstacleGrid[0][0] == 0)
            dp[0] = 1;
        
        for(int i=1; i<m; i++){
            if(obstacleGrid[0][i] == 0)
                dp[i] = dp[i-1];
        }
        
        for(int j=1; j<n; j++){
            if(obstacleGrid[j][0] == 0)
                dp[j*m] = dp[j*m - m];
        }
        
        for(int j=1; j<n; j++)
            for(int i=1; i<m; i++){
                if(obstacleGrid[j][i] == 0)
                    dp[j*m + i] = dp[j*m + i - 1] + dp[j*m - m + i];
            }
        
        return dp[m*n - 1];
    }
};