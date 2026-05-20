class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n=A.length;
        int ans[]=new int[n];
        Map<Integer,Integer>mpp=new HashMap<>();
        for(int i=0;i<n;i++){
            mpp.put(A[i],mpp.getOrDefault(A[i],0)+1);
            mpp.put(B[i],mpp.getOrDefault(B[i],0)-1);
            int common=0;
            for(int x:mpp.keySet()){
                if(mpp.get(x)==0) common++;
            }
            ans[i]=common;
        }
        return ans;
    }
}