class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        ans.emplace_back(intervals[0]);
        int n=intervals.size();

        for(int i=1;i<n;i++){
            if(ans.back()[1]>=intervals[i][0]){
                ans.back()[0]=min(ans.back()[0],intervals[i][0]);
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }else{
                ans.emplace_back(intervals[i]);
            }
        }
        return ans;
    }
};