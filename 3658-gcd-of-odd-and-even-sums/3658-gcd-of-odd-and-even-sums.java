class Solution {

    int gcd(int a,int b){
        while(b!=0){
            int temp=a;
            a=b;
            b=temp%b;
        }
        return a;
    }

    public int gcdOfOddEvenSums(int n) {
        int oddSum=0,evenSum=0;
        int oddCount=n,evenCount=n;
        int i=1;
        while(oddCount>0){
            if(i%2==1){
                oddCount--;
                oddSum+=i;
            }
            i++;
        }

        while(evenCount>0){
            if(i%2==0){
                evenSum+=i;
                evenCount--;
            }
            i++;
        }

        return gcd(Math.max(oddSum,evenSum),Math.min(oddSum,evenSum));
    }
}