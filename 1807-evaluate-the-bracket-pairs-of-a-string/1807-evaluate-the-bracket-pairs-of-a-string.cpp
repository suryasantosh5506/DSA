class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        unordered_map<string,string>mpp;
        for(auto &k:knowledge) mpp[k[0]]=k[1];
        int n=s.size();
        for(int i=0;i<n;){
            if(s[i]=='('){
                i++;
                string word="";
                while(s[i]!=')'){
                    word+=s[i++];
                }
                i++;
                if(mpp.count(word)) ans+=mpp[word];
                else ans+='?';
            }else{
                ans+=s[i++];
            }
        }
        return ans;
    }
};