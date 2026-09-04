typedef long long ll;
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        ll ans=0;
        int penquantity=0;
        while(penquantity*cost1<=total){
            int temp=total;
            temp-=penquantity*cost1;
            ans+=(temp/cost2)+1;
            penquantity++;
        }
        return ans;
    }
};