class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto it:queries){
            vector<pair<string,int>>arr;
            int i=0;
            for(string &st:nums){
                arr.emplace_back(st.substr(st.size()-it[1],it[1]),i++);
            }
            sort(arr.begin(),arr.end());
            ans.emplace_back(arr[it[0]-1].second);
        }
        return ans;
    }
};