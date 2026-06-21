class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Arrays.sort(costs);
        int ans=0;
        for(int x:costs){
            if(coins-x>=0){
                coins-=x;
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
}