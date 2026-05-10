// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        long sum=0;
        int ori=n;
        while(n!=0){
            int rem=n%10;
            sum+=pow(rem,3);
            n/=10;
        }
        return sum==ori;
    }
};