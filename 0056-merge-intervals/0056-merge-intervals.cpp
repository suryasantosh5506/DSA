class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        for(auto it:intervals){
            if(ans.empty()) ans.emplace_back(it);
            else if(ans.back()[1]>=it[0]){
                ans.back()[0]=min(ans.back()[0],it[0]);
                ans.back()[1]=max(ans.back()[1],it[1]);
            }else ans.emplace_back(it);
        }
        return ans;
    }
};