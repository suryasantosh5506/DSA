class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        string ans="";
        for(int i=0;i<n;i++){
            ans+=s[i];
            while(ans.size()>=part.size()){
                if(ans.substr(ans.size()-m)==part){
                    for(int j=0;j<m;j++) ans.pop_back();
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};