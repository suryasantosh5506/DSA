class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        for(char &x:s){
            if(st.empty()) st.push(x);
            else{
                if(abs(st.top()-x)==1 ||(st.top()=='a' && x=='z') || (st.top()=='z' && x=='a'))
                 st.pop();
                else st.push(x);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};