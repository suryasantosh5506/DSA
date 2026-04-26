class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=INT_MIN;
        int cost=prices[0];
        for(auto x:prices){
            int pr=x-cost;
            profit =max(profit,pr);
            cost=min(cost,x);
        }
        return profit;
    }
};