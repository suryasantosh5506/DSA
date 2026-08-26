class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int n=pairs.size();
        
        int ans=0;
        int prev=INT_MIN;

        for(auto &pair:pairs){
            if(prev<pair[0]){
                ans++;
                prev=pair[1];
            }
        }
        return ans;
    }
};