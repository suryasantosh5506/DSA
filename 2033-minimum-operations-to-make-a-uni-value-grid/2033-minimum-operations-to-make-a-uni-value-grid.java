class Solution {
    public int minOperations(int[][] grid, int x) {
        int n=grid.length;
        int m=grid[0].length;
        int arr[]=new int[n*m];
        int index=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[index++]=grid[i][j];
            }
        }

        int rem=arr[0]%x;

        for(int ele:arr){
            if((ele%x)!=rem) return -1;
        }

        Arrays.sort(arr);

        int median=arr[arr.length/2];
        int ans=0;
        for(int ele:arr){
            ans+=Math.abs(ele-median)/x;
        }
        return ans;
    }
}