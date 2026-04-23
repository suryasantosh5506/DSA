class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        int operations=0;

        for(auto x:nums) pq.push(x);

        while(pq.size()>=2){
            long long ele1=pq.top();
            pq.pop();
            if(ele1>=k) break;

            long long ele2=pq.top();
            pq.pop();

            long long nele=min(ele1,ele2)*2ll+max(ele1,ele2);

            pq.push(nele);
            operations++;
        }
        return operations;
    }
};