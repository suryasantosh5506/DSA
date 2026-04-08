class Solution {
    public int xorAfterQueries(int[] nums, int[][] queries) {
        for(int it[]:queries){
            int mod = (int) 1e9 + 7;
            for(int i=it[0];i<=it[1];i+=it[2]){
                nums[i] = (int)((1L * nums[i] * it[3]) % mod);
            }
        }

        int ans=0;
        for(int it:nums){
            ans^=it;
        }
        return ans;
    }
}