class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>>mpp;
        int n=s.size();
        for(int i=0;i<n;i++) mpp[s[i]].emplace_back(i);
        int ans=0;
        for(string &word:words){
            int prev=-1;
            bool valid=true;
            for(char &ch:word){
                auto &v=mpp[ch];
                auto it=upper_bound(v.begin(),v.end(),prev);
                if(it==v.end()){
                    valid=false;
                    break;
                }
                prev=*it;
            }
            if(valid) ans++;
        }
        return ans;
    }
};