class Solution {
public:
    int divide(int dividend, int divisor) {
        // corner case 
        // -2147483648 / -1
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        
        if(dividend == 0)
            return 0;
        
        // use longlong to avoid overflow 
        long long a = labs(dividend);
        long long b = labs(divisor);
        
        int sign = (dividend>0) ^ (divisor>0);
        long long result = 0;
        
        while(a >= b){
            long long n = b;
            long long p = 1;
            while(a > n<<1){
                n = n<<1;
                p = p<<1;
            }
            
            a -= n;
            result += p;
        }
        
        return sign ? -result : result;
    
        
        
    }
};