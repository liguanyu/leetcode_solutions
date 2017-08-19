class Solution
{
   public:
    int
    lengthOfLongestSubstring(string s)
    {
        int len = s.size();
        if (len == 0) {
            return 0;
        }

        int start = 0;
        int end = 0;
        int repeat = 0;
        int index = 1;
        int result = 1;

        while (index <= len - 1) {
            for (int i = start; i <= end; i++) {
                if (s[index] == s[i]) {
                    start = i + 1;
                    break;
                }
            }

            end = end + 1;
            index = index + 1;
            int m = end - start + 1;
            if (m > result) {
                result = m;
            }
        }
        return result;
    }
};
