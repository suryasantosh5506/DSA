class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int n=customers.size();
        int waiting=0;
        int maxi=0;
        int profit=0;
        int round=1;
        int ans=-1;

        for(int &x:customers){
            int curr=0;
            if(x>4){
                waiting+=(x-4);
                curr=4;
            }else{
                while(waiting>0 && x<4){
                    waiting--;
                    x++;
                }
                curr=x;
            }
            int pro=(curr*boardingCost)-runningCost;
            profit+=pro;
            if(profit>maxi){
                maxi=profit;
                ans=round;
            }
            round++;
        }

        while(waiting>0){
            int curr=0;
            if(waiting>4){
                waiting-=4;
                curr=4;
            }else{
                curr=waiting;
                waiting=0;
            }
            int pro=(curr*boardingCost)-runningCost;
            profit+=pro;
            if(profit>maxi){
                maxi=profit;
                ans=round;
            }
            round++;
        }

        return ans;
    }
};