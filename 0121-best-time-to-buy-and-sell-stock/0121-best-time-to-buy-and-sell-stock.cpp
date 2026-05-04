class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int cost=prices[0];
        for(auto x:prices){
            profit=max(profit,x-cost);
            cost=min(cost,x);
        }
        return profit;
    }
};