class Solution {
    public int minJumps(int[] arr) {
        int n=arr.length;
        Queue<int[]>q=new ArrayDeque<>();
        int visited[]=new int[n];
        q.add(new int[] {0,0});
        // {index,steps}
        visited[0]=1;

        Map<Integer,List<Integer>>mpp=new HashMap<>();
        for(int i=0;i<n;i++){
            mpp.putIfAbsent(arr[i],new ArrayList<>());
            mpp.get(arr[i]).add(i);
        }

        while(!q.isEmpty()){
            int[] top=q.peek();
            q.remove();

            int i=top[0];
            int steps=top[1];

            if(i==n-1) return steps;

            if(i-1>=0 && visited[i-1]==0){
                q.add(new int[] {i-1,steps+1});
                visited[i-1]=1;
            }
            if(i+1<n && visited[i+1]==0){
                q.add(new int[] {i+1,steps+1});
                visited[i+1]=1;
            }

            for(int j:mpp.get(arr[i])){
                if(visited[j]==1) continue;
                q.add(new int[] {j,steps+1});
            }
            mpp.get(arr[i]).clear();
        }
        return -1;
    }
}