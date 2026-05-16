class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int maxi=0;
        unordered_map<int,int>mpp;
        while(j<n){
            mpp[s[j]]++;
            while(mpp[s[j]]>1){
                mpp[s[i]]--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};