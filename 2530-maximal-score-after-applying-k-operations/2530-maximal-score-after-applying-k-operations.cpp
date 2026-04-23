typedef long long ll;
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        ll sum=0;

        priority_queue<int>pq;
        for(auto x:nums) pq.push(x);

        while(k>0){
            int top=pq.top();
            pq.pop();

            sum+=top;
            int ele=ceil((double)top/3.0);
            pq.push(ele);

            k--;
        }

        return sum;
    }
};