class Solution {
  public:
  
    int getxor(int n){
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
        return n;      
    }
  
    int findXOR(int l, int r) {
        // code here
        return getxor(r)^getxor(l-1);
    }
};