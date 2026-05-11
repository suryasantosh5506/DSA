// User function Template for Java
class Solution {
    static boolean armstrongNumber(int n) {
        // code here
        int ori=n;
        int sum=0;
        while(n!=0){
            int rem=n%10;
            sum+=Math.pow(rem,3);
            n/=10;
        }
        return (ori==sum);
    }
}