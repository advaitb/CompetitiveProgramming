class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        //here we are only allowed to do at most one transaction
        //In problem 122 - we will be allowed to do multiple there we can keep buying and adding
        //the profit
        if(prices.size() < 2)
        {
            return 0;
        }
        int profit = 0;
        int minprice = prices[0];
        for(int day = 1; day < prices.size(); day++)
        {
            if(prices[day] > prices[day-1])
            {
                profit = max(profit, prices[day]-minprice);
            }
            else
            {
                minprice = min(minprice,prices[day]);
            }
        }
        return profit;
    }
};
