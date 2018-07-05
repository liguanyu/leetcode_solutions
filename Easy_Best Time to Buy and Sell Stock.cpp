class Solution
{
   public:
    int
    maxProfit(vector<int>& prices)
    {
        int n = prices.size();


        if (n == 0 || n == 1) {
            return 0;
        }

        int buy = n - 2;
        int sell = n - 1;
        int bp = prices[buy];
        int sp = prices[sell];
        int result = 0;

        if (sp - bp > result) {
            result = sp - bp;
        }

        while (buy > 0) {
            buy--;
            bp = prices[buy];
            sell--;
            if (prices[sell] > sp) {
                sp = prices[sell];
            }

            if (sp - bp > result) {
                result = sp - bp;
            }
        }

        return result;
    }
};
