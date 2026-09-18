class Solution {
public:
    string reverseWords(string s) {
        string ans="",word="";
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                if(!word.empty()){
                    reverse(word.begin(),word.end());
                    ans+=word+' ';
                }
                word="";
            }else word+=s[i];
        }
        if(word.empty()) ans.pop_back();
        else{
            reverse(word.begin(),word.end());
            ans+=word;
        }
        return ans;
    }
};