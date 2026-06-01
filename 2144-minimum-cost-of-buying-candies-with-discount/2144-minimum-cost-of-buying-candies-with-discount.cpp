class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(),cost.rend());
        int group=2;
        int ans=0;
        for(auto x:cost){
            if(group==0){
                group=2;
                continue;
            }
            group--;
            ans+=x;
        }
        return ans;
    }
};