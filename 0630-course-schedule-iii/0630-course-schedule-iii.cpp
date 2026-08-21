class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(),courses.end(),[](auto &a,auto &b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        });
        int totaldays=0;
        priority_queue<int>pq;

        for(auto it:courses){
            int duration=it[0];
            int lastday=it[1];

            totaldays+=duration;
            pq.push(duration);

            if(totaldays>lastday){
                totaldays-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};