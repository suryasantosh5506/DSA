class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>upper;
        unordered_set<char>lower;
        int cnt=0;

        for(auto ch:word){
            if(isupper(ch)) upper.insert(tolower(ch));
            else lower.insert(ch);
        }

        for(auto ch:lower){
            if(upper.find(ch)!=upper.end()) cnt++;
        }
        return cnt;
    }
};