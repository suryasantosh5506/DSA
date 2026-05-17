class Solution {

    int n;
    int visited[];

    boolean solution(int i,int arr[]){
        if(i<0 || i>=n) return false;
        if(arr[i]==0) return true;
        if(visited[i]==1) return false;
        visited[i]=1;
        return solution(i-arr[i],arr)||solution(i+arr[i],arr);
    }

    public boolean canReach(int[] arr, int start) {
        n=arr.length;
        visited=new int[n];
        Arrays.fill(visited,0);
        return solution(start,arr);
    }
}