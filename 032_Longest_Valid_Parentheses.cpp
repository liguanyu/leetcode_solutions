/*
According to the solution given by leetcode
(1) ...()
        ^
    dp[i] = dp[i-2] + 2

(2) ...))
        ^
    dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int s_len = s.size();
        
        if(s_len <= 1)
            return 0;
        
        vector<int> dp(s_len, 0);
        
        dp[0] = 0;
        if(s.substr(0,2) == "()")
            dp[1] = 2;
        else
            dp[1] = 0;
        
        for(int i=2; i<s_len; i++){
            switch(s[i]){
                case '(' :{
                    dp[i] = 0;
                    break;
                }
                case ')' :{
                    if(s[i-1] == '('){
                        dp[i] = dp[i-2] + 2;
                    }else{
                        if(i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '('){
                            if(i-dp[i-1]-2 >= 0)
                                dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2];
                            else
                                dp[i] = dp[i-1] + 2;
                        }else{
                            dp[i] = 0;
                        }
                    }
                    break;
                }
            }
        }
        
        for(int i=0; i<s_len; i++){
            if(result < dp[i])
                result = dp[i];
        }
        
        return result;
    }
};