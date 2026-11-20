class Solution {
public:

    bool isvowel(char ch){
        unordered_set<char>vowels={'a','e','i','o','u'};
        return vowels.contains(ch);
    }

    int maxVowels(string s, int k) {
        int i=0,j=0;
        int n=s.size();
        int cnt=0;
        int ans=0;

        while(j<n){
            cnt+=isvowel(s[j]);

            while(j-i+1>k){
                cnt-=isvowel(s[i]);
                i++;
            }

            ans=max(ans,cnt);
            j++;
        }
        return ans;
    }
};