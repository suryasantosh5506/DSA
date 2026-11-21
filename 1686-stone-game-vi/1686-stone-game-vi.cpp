class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,int>>pq;
        int n=aliceValues.size();
        for(int i=0;i<n;i++){
            pq.push({aliceValues[i]+bobValues[i],i});
        }
        int turn=0;
        int ascore=0,bscore=0;
        while(!pq.empty()){
            auto [value,ind]=pq.top();
            pq.pop();

            if(turn==0) ascore+=aliceValues[ind];
            else bscore+=bobValues[ind];

            turn=!turn;
        }
            
        return (ascore>bscore)?1:(ascore<bscore)?-1:0;
    }
};