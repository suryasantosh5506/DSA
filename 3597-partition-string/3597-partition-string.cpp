class Solution {
public:
    vector<string> partitionString(string s) {
        vector<string>ans;
        unordered_set<string>seen;
        string seq="";
        int n=s.size();

        for(int i=0;i<n;i++){
            seq+=s[i];
            if(!seen.count(seq)){
                seen.insert(seq);
                ans.emplace_back(seq);
                seq="";
            }
        }
        return ans;
    }
};