class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>ans;
        unordered_map<int,int>mpp;
        // {ele,ind}
        set<int>st(arr.begin(),arr.end());
        int rank=1;
        for(auto it:st){
            mpp[it]=rank++;
        }
        for(auto x:arr) ans.emplace_back(mpp[x]);
        return ans;
    }
};