class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lscore=accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int maxi=lscore;
        int rscore=0;
        int n=cardPoints.size();
        for(int i=n-1;i>=0 && k>0;i--,k--){
            lscore-=cardPoints[k-1];
            rscore+=cardPoints[i];
            maxi=max(maxi,lscore+rscore);
        }
        return maxi;
    }
};