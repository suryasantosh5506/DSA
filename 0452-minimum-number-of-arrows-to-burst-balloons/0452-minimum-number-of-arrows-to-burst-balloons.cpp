class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });

        int n=points.size();
        int ans=0;
        int prev=-1;

        for(auto x:points){
            if(prev==-1 || x[0]>prev){
                ans++;
                prev=x[1];
            }
        }
        return ans;
    }
};