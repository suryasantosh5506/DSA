class Solution {
public:

    unordered_map<string,unordered_set<int>>dp;

    void reverse(stack<string>&st){
        vector<string>temp;
        while(!st.empty()){
            temp.emplace_back(st.top());
            st.pop();
        }
        for(string &x:temp) st.push(x);
    }

    int correctorder(string &s){
        stack<string>st;
        int n=s.size();
        for(int i=0;i<n;){
            if(isdigit(s[i])){
                st.push(string(1,s[i]));
                i++;
            }
            else{
                if(s[i]=='+') st.push(string(1,s[i++]));
                else{
                    int num1=stoi(st.top());
                    st.pop();
                    i++;
                    int num2=s[i]-'0';
                    i++;
                    st.push(to_string(num1*num2));
                }
            }
        }
        reverse(st);
        while(st.size()>1){
            int first=stoi(st.top());
            st.pop();
            char op=st.top()[0];
            st.pop();
            int second=stoi(st.top());
            st.pop();
            st.push(to_string(first+second));
        }
        return stoi(st.top());
    }

    const unordered_set<int>& solution(int i,int j,string &s){
        string key=to_string(i)+":"+to_string(j);
        if(i==j){
            dp[key].insert(s[i]-'0');
            return dp[key];
        }
        if(dp.count(key)) return dp[key];

        for(int k=i+1;k<j;k+=2){
            const auto& left=solution(i,k-1,s);
            const auto& right=solution(k+1,j,s);

            for(int l:left){
                for(int r:right){
                    int val;
                    if(s[k]=='+'){
                        val=l+r;
                    }else{
                        val=l*r;
                    }

                    if(val<=1000) dp[key].insert(val);
                }
            }
        }
        return dp[key];
    }

    int scoreOfStudents(string s, vector<int>& answers) {
        int ori=correctorder(s);
        int n=s.size();
        unordered_set<int>possible=solution(0,n-1,s);
        int ans=0;
        for(int &x:answers) ans+=(x==ori)?5:(possible.count(x))?2:0;
        return ans;
    }
};