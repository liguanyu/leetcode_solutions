class Solution {
public:
    int strStr(string haystack, string needle) {
        int needle_size = needle.size();
        int str_size = haystack.size();
        if(needle_size == 0)
            return 0;
        
        for(int i = 0; i <= str_size-needle_size; i++){
            if(haystack.substr(i,needle_size) == needle)
                return i;
        }
        
        return -1;
    }
};