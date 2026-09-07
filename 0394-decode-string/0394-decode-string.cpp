class Solution {
public:

    int n;
    string ans;

    void solution(int i,stack<int>&number,stack<string>&words,string seq,string word,string &s){
        if(i==n){
            ans=word+seq;
            return;
        }

        if(isdigit(s[i])){
            int num=0;

            for(;i<n;i++){
                if(isdigit(s[i])) num=num*10+(s[i]-'0');
                else break;
            }

            number.push(num);
            solution(i,number,words,seq,word,s);
        }else if(s[i]=='['){

            words.push(seq);
            solution(i+1,number,words,"",word,s);

        }else if(s[i]==']'){

            string temp="";

            for(int i=0;i<number.top();i++){
                temp+=seq;
            }

            seq=words.top()+temp;

            number.pop();
            words.pop();

            solution(i+1,number,words,seq,word,s);
        }else{
            solution(i+1,number,words,seq+s[i],word,s);
        }
    }

    string decodeString(string s) {
        n=s.size();
        stack<int>number;
        stack<string>words;
        solution(0,number,words,"","",s);
        return ans;
    }
};