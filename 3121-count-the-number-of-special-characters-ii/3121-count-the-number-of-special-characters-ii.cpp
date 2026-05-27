class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lastSmall(26,-1);
        vector<int>firstUpper(26,-1);
        int n=word.size();

        for(int i=0;i<n;i++){
            if(islower(word[i])) lastSmall[word[i]-'a']=i;
            else{
                if(firstUpper[word[i]-'A']==-1){
                    firstUpper[word[i]-'A']=i;
                }
            }
        }

        int ans=0;

        for(int i=0;i<26;i++){
            if(lastSmall[i]!=-1 && firstUpper[i]!=-1 && lastSmall[i]<firstUpper[i]){
                ans++;
            }
        }
        return ans;
    }
};