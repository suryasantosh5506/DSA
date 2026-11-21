class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,' ');
        char ch='z';
        int idx=n-1;
        while(k>0){
            // make sure that we have enough value for k to fill the remaining characters
            if((ch-'a'+1)<=k-idx){
                ans[idx--]=ch;
                k-=(ch-'a'+1);
            }
            else ch--;
        }
        return ans;
    }
};