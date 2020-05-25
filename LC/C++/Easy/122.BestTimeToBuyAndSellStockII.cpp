class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
     //we need to understand that sum(  Day x - Day y + Day z - Day w ..)
     //is just the same as buying on the smallest day and selling on the last day
     // as prices are additive;
    
        int profit  = 0;
        int num_days = prices.size();
        if(num_days < 2)
        {
            return 0;
        }
        int curr_price = prices[0];
        int subprofit;
        for(int i = 1; i < num_days; i++)
        {
            subprofit = prices[i]-curr_price;
            if (subprofit > 0)
            {
                profit+=subprofit;

            }
                curr_price = prices[i];
        }
        return profit;
    }
};
