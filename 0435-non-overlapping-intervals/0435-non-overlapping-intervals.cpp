class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto a,auto b){
            return a[1]<b[1];
        });
        int cnt=0;
        int n=intervals.size();
        int last=INT_MIN;
        for(auto x:intervals){
            if(last<=x[0]){
                cnt++;
                last=x[1];
            }
        }
        return n-cnt;
    }
};