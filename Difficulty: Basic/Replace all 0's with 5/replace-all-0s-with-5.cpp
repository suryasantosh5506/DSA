/*you are required to complete this method*/
class Solution {
  public:
    int convertFive(int n) {
        // Your code here
        if(n==0) return 5;
        int res=0;
        int place=1;
        while(n!=0){
            int rem=n%10;
            if(rem==0) rem=5;
            res+=place*rem;
            n/=10;
            place*=10;
        }
        return res;
    }
};