class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        string word="";

        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                if(!word.empty()){
                    reverse(word.begin(),word.end());
                    ans+=word+" ";
                }
                word="";
            }else{
                word+=s[i];
            }
        }
        if(!word.empty()){
            reverse(word.begin(),word.end());
            ans+=word;
        }else ans.pop_back();
        return ans;
    }
};