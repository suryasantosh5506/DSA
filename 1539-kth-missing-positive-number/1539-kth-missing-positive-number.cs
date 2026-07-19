public class Solution {
    public int FindKthPositive(int[] arr, int k) {
        int n=arr.Length;
        foreach(int x in arr){
            if(x>k) break;
            k++;
        }
        return k;
    }
}