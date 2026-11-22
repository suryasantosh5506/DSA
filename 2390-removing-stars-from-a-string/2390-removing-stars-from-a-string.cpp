class Solution {
public:
    string removeStars(string s) {
        string ans="";
        for(char &x:s){
            if(x=='*') ans.pop_back();
            else ans+=x;
        }
        return ans;
    }
};