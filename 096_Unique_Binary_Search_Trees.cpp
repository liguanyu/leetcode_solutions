class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 0;
        
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int number=2; number<=n; number++){
            dp[number] = 0;
            for(int i=1; i<=number; i++){
                dp[number] += dp[i-1] * dp[number-i];
            }
        }
        
        return dp[n];
    }
};