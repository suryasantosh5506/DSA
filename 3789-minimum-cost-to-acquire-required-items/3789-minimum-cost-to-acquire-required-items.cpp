typedef long long ll;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll ans=0;
        int cost=min(costBoth,cost1+cost2);
        int items=min(need1,need2);
        ans+=1ll*cost*items;
        need1-=items;
        need2-=items;
        cost=min(costBoth,cost1);
        ans+=1ll*cost*need1;
        cost=min(costBoth,cost2);
        ans+=1ll*cost*need2;
        return ans;
    }
};