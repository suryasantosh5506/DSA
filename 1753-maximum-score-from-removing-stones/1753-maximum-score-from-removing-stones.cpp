class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);

        int ans=0;

        while(pq.size()>=2){
            a=pq.top();
            pq.pop();

            b=pq.top();
            pq.pop();

            a--;
            b--;
            ans++;

            if(a>0) pq.push(a);
            if(b>0) pq.push(b);
        }
        return ans;
    }
};