class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        unordered_map<int,unordered_set<int>>mpp;
        int n=groupSizes.size();
        // {groupsize,ele}
        for(int i=0;i<n;i++){
            mpp[groupSizes[i]].insert(i);
        }

        for(auto it:mpp){
            auto [size,st]=it;
            while(!st.empty()){
                int n=size;
                vector<int>arr;
                for(auto it:st){
                    if(n<=0) break;
                    arr.emplace_back(it);
                    n--;
                }

                for(int &x:arr) st.erase(x);
                ans.emplace_back(arr);
            }
        }
        return ans;
    }
};