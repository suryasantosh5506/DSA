class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        if(r==0) return 1;
        long long ans=1;
        for(int i=1;i<=r;i++){
            ans*=(n-i+1);
            ans/=i;
        }
        return ans;
    }
};

