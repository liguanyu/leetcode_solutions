class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        
        vector<int> dp(len, 0);
        dp[0] = nums[0] > 0 ? nums[0] : 0;
            
        for(int i=1; i<len; i++){
            dp[i] = dp[i-1]+nums[i];
            dp[i] = dp[i]>0 ? dp[i] : 0;
        }
        
        int result = max(dp);
        if(result == 0){
            result = max(nums);
        }
        return result;
            
    }
    
    int max(vector<int>& vec){
        int result = vec[0];
        for(int &a : vec){
            if(a>result)
                result = a;
        }
        return result;
    }
};