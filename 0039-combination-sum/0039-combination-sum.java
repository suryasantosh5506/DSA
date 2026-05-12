class Solution {

    void solution(int i,int tgt,List<Integer>seq,int candidates[],List<List<Integer>>ans){
        if(i==candidates.length){
            if(tgt==0){
                ans.add(new ArrayList<>(seq));
            }
            return;
        }

        if(tgt<0) return;

        seq.add(candidates[i]);
        solution(i,tgt-candidates[i],seq,candidates,ans);
        seq.remove(seq.size()-1);
        solution(i+1,tgt,seq,candidates,ans);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>>ans=new ArrayList<>();
        List<Integer>seq=new ArrayList<>();
        solution(0,target,seq,candidates,ans);
        return ans;
    }
}