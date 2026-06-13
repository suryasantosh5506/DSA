class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuilder ans=new StringBuilder();
        for(String word:words){
            int wt=0;
            for(char ch:word.toCharArray()){
                wt+=weights[ch-'a'];
            }
            wt%=26;
            ans.append((char)('z'-wt));
        }
        return ans.toString();
    }
}