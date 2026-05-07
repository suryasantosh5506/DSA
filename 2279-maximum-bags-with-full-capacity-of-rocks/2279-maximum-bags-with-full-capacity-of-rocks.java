class Solution {
    public int maximumBags(int[] capacity, int[] rocks, int additionalRocks) {
        int n=capacity.length;
        int arr[][]=new int[n][2];

        for(int i=0;i<n;i++){
            arr[i]=new int[] {capacity[i],rocks[i]};
        }

        Arrays.sort(arr, (a, b) ->
            (a[0] - a[1]) - (b[0] - b[1])
        );

        int i=0;

        for(;i<n;i++){
            int rem=arr[i][0]-arr[i][1];
            if(additionalRocks-rem<0) break;
            additionalRocks-=rem;
        }
        return i;
    }
}