typedef long long ll;
class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        unordered_map<int,ll>mpp;
        int n=s.size();
        ll total=0;
        for(int i=0;i<n;i++){
            mpp[s[i]]+=cost[i];
            total+=cost[i];
        }
        ll maxi=0;
        for(auto it:mpp) maxi=max(maxi,it.second);
        return total-maxi;
    }
};