class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int ans=0;
        while(n!=0){
            ans++;
            n&=(n-1);
        }
        return ans;
    }
};