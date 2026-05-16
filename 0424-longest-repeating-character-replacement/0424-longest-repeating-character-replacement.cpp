class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        int maxfreq=0;
        unordered_map<int,int>mpp;
        int n=s.size();
        int ans=0;

        while(j<n){
            mpp[s[j]]++;
            maxfreq=max(maxfreq,mpp[s[j]]);
            if((j-i+1)-maxfreq>k){
                mpp[s[i]]--;
                if(mpp[s[i]]==0) mpp.erase(s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};