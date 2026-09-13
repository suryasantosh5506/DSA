class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double waitingtime=0;
        double n=customers.size();
        int time=0;
        for(auto it:customers){
            int start=max(time,it[0]);
            waitingtime+=start-it[0];
            int complete=start+it[1];
            waitingtime+=(complete-start);
            time=complete;
        }
        return waitingtime/n;
    }
};