/*
hint from leetcode forum

if word1[i-1] == word2[j-1]
    dp[j][i] = dp[j-1][i-1];
else
    choose min from replace/insert/delete
    replace : dp[j][i] = dp[j-1][i-1] + 1;
    insert : dp[j][i] = dp[j-1][i] + 1;
    delete : dp[j][i] = dp[j][i-1] + 1;
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        
        vector<vector<int>> dp(len2+1, vector<int>(len1+1, 0));
        
        for(int i=0; i<len1+1; i++)
            dp[0][i] = i;
        
        for(int j=0; j<len2+1; j++)
            dp[j][0] = j;
        
        for(int j=1; j<len2+1; j++)
            for(int i=1; i<len1+1; i++){
                if(word1[i-1] == word2[j-1]){
                    dp[j][i] = dp[j-1][i-1];
                }else{
                    dp[j][i] = min(dp[j-1][i-1]+1, dp[j][i-1]+1, dp[j-1][i]+1);
                }
            }
    
        
        return dp[len2][len1];
    }
    
    int min(int a, int b, int c)
    {
        if(a < b)
            return a<c ? a : c;
        else
            return b<c ? b : c;
    }
};