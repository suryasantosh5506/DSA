class Solution {
    public static int countDigits(int n) {
        // Code here
        int cnt=0;
        while(n!=0){
            cnt++;
            n/=10;
        }
        return cnt;
    }
}
