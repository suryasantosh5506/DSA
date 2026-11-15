class Solution {
public:

    void reverse(stack<string>&st){
        vector<string>temp;
        while(!st.empty()){
            temp.emplace_back(st.top());
            st.pop();
        }
        for(string &x:temp) st.push(x);
    }

    void skipspaces(int &i,string &s){
        while(i<s.size() && s[i]==' ') i++;
    }

    string getnum(int &i,string &s){
        int n=s.size();
        string num="";
        while(i<n && isdigit(s[i])){
            num+=s[i++];
        }
        return num;
    }

    int calculate(string s) {
        stack<string>st;
        int i=0;
        int n=s.size();
        for(int i=0;i<n;){
            skipspaces(i,s);
            if(i>=n) break;
            if(isdigit(s[i])){
                st.push(getnum(i,s));
            }
            else{
                if(s[i]=='+') st.push(string(1,s[i++]));
                else if(s[i]=='-') st.push(string(1,s[i++]));
                else if(s[i]=='*'){
                    int top=stoi(st.top());
                    st.pop();
                    i++;
                    skipspaces(i,s);
                    int ele=top*stoi(getnum(i,s));
                    st.push(to_string(ele));
                }else{
                    int top=stoi(st.top());
                    st.pop();
                    i++;
                    skipspaces(i,s);
                    int ele=top/stoi(getnum(i,s));
                    st.push(to_string(ele));
                }
            }
        }
        
        reverse(st);

        while(st.size()>1){
            int first=stoi(st.top());
            st.pop();
            char operation=st.top()[0];
            st.pop();
            int second=stoi(st.top());
            st.pop();
            switch(operation){
                case '+' :
                    st.push(to_string(first+second));
                    break;
                case '-':
                    st.push(to_string(first-second));
                    break;
            }
        }
        return stoi(st.top());
    }
};