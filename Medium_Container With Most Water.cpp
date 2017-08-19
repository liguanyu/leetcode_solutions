class Solution
{
   public:
    int
    maxArea(vector<int>& height)
    {
        int result = 0;
        int n = height.size();

        int i = 0;
        int j = n - 1;
        int v = 0;

        while (i < j) {
            int v = (j - i) * ((height[i] < height[j]) ? height[i] : height[j]);
            if (result < v) {
                result = v;
            }

            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return result;
    }
};
