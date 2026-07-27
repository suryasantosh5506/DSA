class Solution {
public:
    string customSortString(string order, string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        for(auto &ch:s) mpp[ch]++;
        string ans="";
        for(auto &ch:order){
            if(mpp.count(ch)){
                ans+=string(mpp[ch],ch);
                mpp.erase(ch);
            }
        }
        for(auto it:mpp){
            ans+=string(it.second,it.first);
        }
        return ans;
    }
};