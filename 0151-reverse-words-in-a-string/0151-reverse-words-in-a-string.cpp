class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string word="";

        for(int i=s.size()-1;i>=0;i--){
            if(!isalnum(s[i])){
                if(!word.empty()){
                    reverse(word.begin(),word.end());
                    ans+=word+" ";
                    word="";
                }
            }else{
                word+=s[i];
            }
        }

        if(!word.empty()){
            reverse(word.begin(),word.end());
            ans+=word;
            word="";          
        }else{
            ans.pop_back();
        }
        return ans;
    }
};