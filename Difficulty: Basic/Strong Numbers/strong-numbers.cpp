class Solution {
  public:
  
    int factorial(int n){
        if(n<=1) return n;
        return n*factorial(n-1);
    }
  
    int is_StrongNumber(int n) {
        // Code here.
        int ans=0;
        int ori=n;
        while(n!=0){
            int rem=n%10;
            ans+=factorial(rem);
            n/=10;
        }
        return (ans==ori);
    }
};
