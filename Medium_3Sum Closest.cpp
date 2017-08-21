class Solution
{
   public:
    int
    threeSumClosest(vector<int>& nums, int target)
    {
        int result = 0;
        int n = nums.size();

        if (n < 3) {
            return result;
        }

        vector<int> num(nums);
        sort(num.begin(), num.end());

        int i = 0;
        int j = 1;
        int m = n - 1;
        result = num[i] + num[j] + num[m];
        while (i < n - 2) {
            j = i + 1;
            m = n - 1;
            while (j < m) {
                int temp = num[i] + num[j] + num[m];
                if (abs(temp - target) < abs(result - target)) result = temp;
                if (temp == target) {
                    return result;
                } else if (temp - target < 0) {
                    j++;
                } else if (temp - target > 0) {
                    m--;
                }
            }
            i++;
            while (num[i] == num[i - 1]) {
                i++;
                if (i == n) {
                    break;
                }
            }
        }

        return result;
    }
};
