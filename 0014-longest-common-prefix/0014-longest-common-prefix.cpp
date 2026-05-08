class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string first=strs[0];
        string last=strs[n-1];
        n=min(first.size(),last.size());
        int i=0;
        for(;i<n;i++){
            if(first[i]!=last[i]) break;
        }
        return first.substr(0,i);
    }
};