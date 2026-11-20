class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        int maxi=0;
        while(j<n){
            if(j!=0 && s[j]!=s[j-1]+1){
                i=j;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};