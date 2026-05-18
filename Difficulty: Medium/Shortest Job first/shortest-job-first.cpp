class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        int n=bt.size();
        sort(bt.begin(),bt.end());
        int ans=0;
        int time=0;
        for(auto x:bt){
            ans+=time;
            time+=x;
        }
        return ans/n;
    }
};