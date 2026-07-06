class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==i) continue;
                int a=intervals[i][0],b=intervals[i][1];
                int c=intervals[j][0],d=intervals[j][1];
                if(c<=a && b<=d){
                    cnt++;
                    break;
                }
            }
        }
        return n-cnt;
    }
};