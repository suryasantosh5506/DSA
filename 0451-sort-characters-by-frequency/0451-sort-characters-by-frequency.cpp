class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(char &x:s) mpp[x]++;
        vector<pair<int,char>>arr;
        for(auto it:mpp) arr.emplace_back(it.second,it.first);
        sort(arr.rbegin(),arr.rend());
        string ans="";
        for(auto it:arr) ans+=string(it.first,it.second);
        return ans;
    }
};