public class Solution {
    public int FindKthPositive(int[] arr, int k) {
        int n=arr.Length;
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missingCnt=arr[mid]-(mid+1);
            if(missingCnt<k) low=mid+1;
            else high=mid-1;
        }
        if(high==-1) return k;
        int missing=arr[high]-(high+1);
        int req=k-missing;
        return arr[high]+req;
    }
}