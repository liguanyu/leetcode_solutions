class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if(n==0||n==1){return 0;}
        
        if(n==2){
            if(prices[1] - prices[0] > 0){
                return prices[1] - prices[0];
            }
        }
        
        int result = 0;
        
        int buy = n-2;
        int sell = n-1;
        int bp = prices[buy];
        int sp = prices[sell];
        
        while(buy>0){
            buy--;
            if(prices[buy] <= bp){
                bp = prices[buy];
                sell--;
                if(prices[sell] > sp){
                    sp = prices[sell];
                }
            }else if(prices[buy] > bp){
                if(sp-bp>0){
                    result = sp - bp + result;
                }
                
                if(buy==0){break;}

                buy = buy - 1;
                sell = buy + 1;
                bp = prices[buy];
                sp = prices[sell];                
            }
            
            if(buy==0){
                if(sp-bp>0){
                    result += sp - bp;
                }
            }

        }
        
        return result;
    }
};
