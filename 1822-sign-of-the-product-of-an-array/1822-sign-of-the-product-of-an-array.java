class Solution {
    public int arraySign(int[] nums) {
        int neg=0;
        for(int x:nums){
            if(x<0) neg++;
            if(x==0) return 0;;
        }
        return (neg%2==0)?1:-1;
    }
}