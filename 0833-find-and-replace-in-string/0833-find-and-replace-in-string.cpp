class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        unordered_map<int,vector<int>>mpp;
        string ans="";
        int m=indices.size();
        for(int i=0;i<m;i++) mpp[indices[i]].emplace_back(i);
        int n=s.size();
        for(int i=0;i<n;){
            if(mpp.count(i)){
                bool replaced=false;
                for(int &idx:mpp[i]){
                    string sub=s.substr(i,sources[idx].size());
                    if(sub==sources[idx]){
                        ans+=targets[idx];
                        replaced=true;
                        i+=sub.size();
                        break;
                    }
                }
                if(!replaced) ans+=s[i++];
            }else{
                ans+=s[i++];
            }
        }
        return ans;
    }
};