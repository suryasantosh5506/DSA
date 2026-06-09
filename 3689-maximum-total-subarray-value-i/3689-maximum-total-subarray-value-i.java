class Solution {
    public long maxTotalValue(int[] nums, int k) {
        long mini=Arrays.stream(nums).min().getAsInt();
        long maxi=Arrays.stream(nums).max().getAsInt();
        return 1l*k*(maxi-mini);
    }
}