class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        set<vector<int>>st;
        int n=intervals.size();
        for(int i=0;i<n;i++) st.insert({intervals[i][0],i});
        vector<int>ans;
        for(int i=0;i<n;i++){
            auto it=st.lower_bound({intervals[i][1],-1});
            int index=0;
            if(it==st.end()) index=-1;
            else index=(*it)[1];
            ans.emplace_back(index);
        }
        return ans;
    }
};