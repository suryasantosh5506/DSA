class Solution {
public:

    int n,m;
    int ans=INT_MAX;

    void solution(int j,int cost,vector<int>&toppings,int target){
        if(abs(ans-target)>abs(cost-target)){
            ans=cost;
        }else if(abs(ans-target)==abs(cost-target) && cost<ans) ans=cost;

        if(j==m) return;

        
        solution(j+1,cost,toppings,target);
        solution(j+1,cost+toppings[j],toppings,target);
        solution(j+1,cost+2*toppings[j],toppings,target);
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        n=baseCosts.size();
        m=toppingCosts.size();
        for(auto base:baseCosts) solution(0,base,toppingCosts,target);
        return ans;
    }
};