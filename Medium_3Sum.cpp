class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        if(n<3){return result;}
        
        vector<int> num(nums);
        sort(num.begin(),num.end());
        
        int i=0;
        int j=1;
        int m=n-1;
        while(i<n-2){
            j=i+1;
            m=n-1;
            while(j<m){
                int temp = num[i] + num[j] + num [m];
                if(temp == 0){
                    vector<int> a{num[i] , num[j] , num [m]};
                    result.push_back(a);
                    j++;
                    while(num[j]==num[j-1]){j++;if(j==n){break;}}
                    m--;
                    while(num[m]==num[m+1]){m--;if(m==-1){break;}}
                }
                else if(temp<0){
                    j++;
                }
                else if(temp>0){
                    m--;
                }
            }
            i++;
            while(num[i]==num[i-1]){i++;if(i==n){break;}}
        }
        
        return result;
        
    }
};
