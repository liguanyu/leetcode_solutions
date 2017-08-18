class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        int mid = 0;
        int result = 0;
        int start = 0;
        for(mid = 0;mid < len;mid++){
            int m =0;
            while(s[mid-m] == s[mid+m]){
                if(2*m+1 > result){
                    result = 2*m+1;
                    start = mid - m;
                }
                if(mid - m == 0||mid + m == len - 1){
                    break;
                }
                m++;
            }
        }
        
        for(mid = (result-1)/2;mid < len;mid++){
            int m = 1;
            while(s[mid-m+1] == s[mid+m]){
                if(2*m > result){
                    result = 2*m;
                    start = mid - m + 1;
                }
                if(mid - m + 1 == 0||mid + m == len - 1){
                    break;
                }
                m++;
            }
        }
        return s.substr(start, result);
    }
};
