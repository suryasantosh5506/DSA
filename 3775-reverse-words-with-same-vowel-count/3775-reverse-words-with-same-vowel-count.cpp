class Solution {
public:
    string reverseWords(string s) {
        int req=0,cnt=0;
        int n=s.size();
        int i=0;
        unordered_set<char>vowels={'a','e','i','o','u'};
        string ans="";
        while(i<n && s[i]!=' '){
            ans+=s[i];
            if(vowels.count(s[i])) cnt++;
            i++;
        }
        if(i==n) return ans;
        ans+=' ';
        req=cnt;
        cnt=0;
        i++;

        string word="";
        while(i<n){
            if(s[i]==' '){
                if(cnt==req){
                    reverse(word.begin(),word.end());
                }
                ans+=word+' ';
                word="";
                cnt=0;
            }else{
                word+=s[i];
                if(vowels.count(s[i])) cnt++;
            }
            i++;
        }

        if(!word.empty()){
            if(cnt==req){
                reverse(word.begin(),word.end());
            }
            ans+=word;
            word="";
        }else ans.pop_back();
        return ans;
    }
};