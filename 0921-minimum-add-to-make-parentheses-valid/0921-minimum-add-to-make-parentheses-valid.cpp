class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int ans=INT_MAX,cnt=0;
        for(char &x:s){
            if(x=='(') st.push('(');
            else{
                if(st.empty()) cnt++;
                else st.pop();
            }
        }
        cnt+=st.size();
        return cnt;
    }
};