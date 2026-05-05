class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        int n=tokens.length;
        int i=0,j=n-1;
        Arrays.sort(tokens);
        int score=0;
        int maxi=0;

        while(i<=j){
            if(power>=tokens[i]){
                power-=tokens[i];
                i++;
                score++;
                maxi=Math.max(maxi,score);
            }else if(score>=1){
                score--;
                power+=tokens[j];
                j--;
            }else break;
        }
        return maxi;
    }
}