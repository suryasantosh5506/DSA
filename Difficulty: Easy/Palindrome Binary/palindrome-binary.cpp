class Solution {
  public:
    int isPallindrome(long long int N) {
        // code here
        string s="";
        
        while(N!=0){
            s+=('0'+(N%2));
            N/=2;
        }
        
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
};