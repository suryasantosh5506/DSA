typedef long long ll;
class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        int cnt=0;
        unordered_map<char,int>mpp;
        for(char &x:word2) mpp[x]++;
        int i=0,j=0;
        ll ans=0;
        while(j<n){
            if(mpp[word1[j]]>0) cnt++;
            mpp[word1[j]]--;

            while(cnt==m){
                mpp[word1[i]]++;
                if(mpp[word1[i]]>0) cnt--;
                i++;
                ans+=(n-j);
            }
            j++;
        }
        return ans;
    }
};