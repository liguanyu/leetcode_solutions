class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        string result;
        int n = numRows;
        
        if(n==1){
            return s;
        }
        
        int k = len / (2*(n-1));
        int kk = len % (2*(n-1));
        
        for (int i = 0;i < n;i++){
            string temps(k,'0');
            if(i==0){
                for(int j=0;j < k;j++){
                    temps[j] = s[j*2*(n-1)];
                }
                if(kk>0){
                    temps += s[k*2*(n-1)];
                }
            }
            else if(i == n-1){
                
                for(int j = 0;j < k;j++){
                    temps[j] = s[j*2*(n-1)+n-1];
                }
                if(kk >= n){
                    temps += s[k*2*(n-1)+n-1];
                }
            }
            else{
                temps += temps;
                for(int j = 0;j < k;j++){
                    temps[2*j] = s[j*2*(n-1)+i];
                    temps[2*j+1] = s[j*2*(n-1)+2*(n-1)-i];
                }
                if(kk>=i+1){
                    temps += s[k*2*(n-1)+i];
                }
                if(kk>=2*(n-1)-i+1){
                    temps += s[k*2*(n-1)+2*(n-1)-i];
                }
            }
            
            result += temps;
        }
        
        return result;
    }
};
