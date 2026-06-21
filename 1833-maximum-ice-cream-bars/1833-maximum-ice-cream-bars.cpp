class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans=0;
        for(int &x:costs){
            if(coins-x>=0){
                coins-=x;
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};