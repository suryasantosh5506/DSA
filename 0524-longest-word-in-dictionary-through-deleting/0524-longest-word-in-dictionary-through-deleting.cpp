class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n=dictionary.size();
        string ans="";
        for(string word:dictionary){
            int i=0,j=0;
            while(i<s.size() && j<word.size()){
                if(s[i]==word[j]) j++;
                i++;
            }
            if(j==word.size()){
                if(word.size()>ans.size()) ans=word;
                else if(word.size()==ans.size()) ans=min(ans,word);
            }
        }
        return ans;
    }
};