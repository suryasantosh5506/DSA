class Solution {
    void segregate0and1(int[] arr) {
        // code here
        int j=0;
        int n=arr.length;
        
        for(;j<n;j++){
            if(arr[j]==1) break;
        }
        
        for(int i=j+1;i<n;i++){
            if(arr[i]!=1){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                j++;
            }
        }
    }
}
