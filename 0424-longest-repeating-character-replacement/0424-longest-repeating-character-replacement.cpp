class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int maxFreq=0;
        int ans=0;
        int i=0,j=0;
        while(j<n){
            mpp[s[j]]++;
            maxFreq=max(maxFreq,mpp[s[j]]);
            while((j-i+1)-maxFreq>k){
                mpp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};