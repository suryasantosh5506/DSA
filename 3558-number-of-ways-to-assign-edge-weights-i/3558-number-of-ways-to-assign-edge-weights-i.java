class Solution {

    final int mod=(int)1e9+7;
    int maxDepth=-1;

     void solution(int root, int parent, int depth,List<List<Integer>>tree) {
        maxDepth=Math.max(maxDepth,depth);

        for (int it:tree.get(root)) {
            if (it!=parent) {
                solution(it,root,depth+1,tree);
            }
        }
    }

    long mypower(long base,long exp){
        long ans=1;
        while(exp!=0){
            if(exp%2==0){
                base=(base*base)%mod;
                exp/=2;
            }else{
                ans=(ans*base)%mod;
                exp--;
            }
        }
        return ans;
    }

    public int assignEdgeWeights(int[][] edges) {
        int n=edges.length;
        List<List<Integer>>tree=new ArrayList<>();

        for(int i=0;i<=n+1;i++){
            tree.add(new ArrayList<>());
        }

        for(int it[]:edges){
            tree.get(it[0]).add(it[1]);
            tree.get(it[1]).add(it[0]);
        }
        solution(1,-1,0,tree);
        if(maxDepth==0) return 0;
        return (int)mypower(2,maxDepth-1);
    }
}