class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto x:s){
            if(x=='(' || x=='[' || x=='{') st.push(x);
            else{
                if(st.empty()) return false;
                if(x==')' && st.top()!='(') return false;
                if(x==']' && st.top()!='[') return false;
                if(x=='}' && st.top()!='{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};