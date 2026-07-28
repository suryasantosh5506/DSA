class Solution {
public:
    string smallestPalindrome(string s) {
        map<char,int>mpp;
        int n=s.size();
        for(char &ch:s) mpp[ch]++;
        string left="";
        string middle="";
        for(auto &it:mpp){
            left+=string(it.second/2,it.first);
            if(it.second%2==1) middle+=it.first;
        }
        string right=left;
        reverse(right.begin(),right.end());
        return left+middle+right;
    }
};