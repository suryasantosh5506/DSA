class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(char &x:s){
            if(x=='*'){
                if(!ans.empty()) ans.pop_back();
            } 
            else if(x=='#') ans+=ans;
            else if(x=='%') reverse(ans.begin(),ans.end());
            else ans+=x;
        }
        return ans;
    }
};