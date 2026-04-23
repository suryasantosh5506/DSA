class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto x:piles) pq.push(x);

        while(k>0){
            int top=pq.top();
            pq.pop();

            int ele=ceil((double)top/2.0);
            pq.push(ele);

            k--;
        }

        int ans=0;

        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        
        return ans;
    }
};