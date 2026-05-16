class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=accumulate(cardPoints.begin(),cardPoints.begin()+k,0);
        int maxi=lsum;
        int n=cardPoints.size();
        int rsum=0;
        int right=n-1;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[right--];
            maxi=max(maxi,lsum+rsum);
        }
        return maxi;
    }
};