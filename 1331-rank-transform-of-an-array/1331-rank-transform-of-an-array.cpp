class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>mpp;
        set<int>st(arr.begin(),arr.end());
        int rank=1;
        for(auto x:st) mpp[x]=rank++;
        vector<int>ans;
        for(int &x:arr) ans.emplace_back(mpp[x]);
        return ans;
    }
};