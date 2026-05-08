class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int cnt=0;

        for(auto x:s){
            if(x=='('){
                if(cnt>0) res+='(';
                cnt++;
            }else{
                cnt--;
                if(cnt>0) res+=')';
            }
        }
        return res;
    }
};