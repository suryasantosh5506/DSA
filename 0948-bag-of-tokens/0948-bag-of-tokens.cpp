class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int maxScore=0;
        int n=tokens.size();

        int i=0,j=n-1;

        while(i<=j){
            if(power>=tokens[i]){
                score++;
                maxScore=max(maxScore,score);
                power-=tokens[i];
                i++;
            }else if(score>=1){
                power+=tokens[j];
                score--;
                j--;
            }else break;
        }
        return maxScore;
    }
};