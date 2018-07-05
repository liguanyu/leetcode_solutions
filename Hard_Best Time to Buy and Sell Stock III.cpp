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

        int result = 0;
        int a = 0, b = 0;

        result += maxProfitSingle(prices, a, b, 0, n - 1);

        vector<int> rprices = prices;
        reverse(rprices.begin(), rprices.end());

        int aa, bb;

        int temp1 = maxProfitSingle(prices, aa, bb, 0, a - 1);
        int temp2 = maxProfitSingle(prices, aa, bb, b + 1, n - 1);
        int temp3 = maxProfitSingle(rprices, aa, bb, n - b, n - a - 2);

        if (temp1 < temp2) {
            temp1 = temp2;
        }
        if (temp1 < temp3) {
            temp1 = temp3;
        }

        return result + temp1;
    }

    int
    maxProfitSingle(vector<int>& prices, int& a, int& b, int c, int d)
    {
        int n = d - c + 1;

        if (n <= 1) {
            return 0;
        }

        int buy = d - 1;
        int sell = d;
        a = buy;
        b = sell;
        int btemp = sell;
        int bp = prices[buy];
        int sp = prices[sell];
        int result = 0;

        if (sp - bp > result) {
            result = sp - bp;
        }

        while (buy > c) {
            buy--;
            bp = prices[buy];
            sell--;
            if (prices[sell] > sp) {
                sp = prices[sell];
                btemp = sell;
            }

            if (sp - bp > result) {
                result = sp - bp;
                a = buy;
                b = btemp;
            }
        }

        return result;
    }
};
