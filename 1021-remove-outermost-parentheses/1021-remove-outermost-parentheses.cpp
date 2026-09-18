class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string ans="";
        for(char &x:s){
            if(x=='('){
                if(cnt>0) ans+='(';
                cnt++;
            }else{
                cnt--;
                if(cnt>0) ans+=')';
            }
        }
        return ans;
    }
};