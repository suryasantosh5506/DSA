class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a=0,b=0;
        int n=s.size();
        for(char &x:s){
            if(x=='a') a++;
            else b++;
        }
        return n-min(a,b)*2;
    }
};