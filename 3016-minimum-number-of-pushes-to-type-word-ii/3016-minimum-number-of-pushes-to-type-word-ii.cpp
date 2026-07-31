class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mpp;
        vector<pair<char,int>>arr;
        for(char &ch:word) mpp[ch]++;
        for(auto it:mpp) arr.emplace_back(it);
        sort(arr.begin(),arr.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });
        int ans=0;
        int keys=8;
        int pushes=1;
        for(auto &it:arr){
            if(keys==0){
                keys=8;
                pushes++;
            }
            ans+=(it.second*pushes);
            keys--;
        }
        return ans;
    }
};