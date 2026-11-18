class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int cnt=0;
        for(char &x:s){
            if(x=='('){
                st.push(x);
                cnt++;
            }else{
                if(st.empty()) cnt++;
                else{
                    cnt--;
                    st.pop();
                }
            }
        }
        return cnt;
    }
};