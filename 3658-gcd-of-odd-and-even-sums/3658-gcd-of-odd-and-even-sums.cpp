class Solution {
public:
    int gcdOfOddEvenSums(int n) {
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

        return __gcd(oddSum,evenSum);
    }
};