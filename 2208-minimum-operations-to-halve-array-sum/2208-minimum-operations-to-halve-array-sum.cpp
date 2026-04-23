class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        priority_queue<double>pq;
        for(auto x:nums){
            pq.push(x);
            sum+=x;
        }
        double original=sum;
        int operations=0;
        while(!pq.empty()){
            double top=pq.top();
            pq.pop();

            double ele=(double)top/2.0;
            pq.push(ele);
            sum=sum-top+ele;

            operations++;
            if(sum<=((double)original/2.0)) break;
        }
        return operations;
    }
};