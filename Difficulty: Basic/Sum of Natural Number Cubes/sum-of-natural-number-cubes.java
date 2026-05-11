// User function Template for Java

class Solution {
    int sumOfSeries(int n) {
        // code here
        int sum=0;
        for(int i=1;i<=n;i++) sum+=Math.pow(i,3);
        return sum;
    }
}