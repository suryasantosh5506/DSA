class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n<=0 || (n&(n-1))!=0) return -1;
        if(__builtin_popcount(n)>1) return -1;
        int pos = 1;
        while (n>0) {
            if(n%2==1) return pos;
            pos++;
            n/=2;
        }
        return -1;
    }
};