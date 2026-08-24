class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        if(n<3) return 0;
        int cnt=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mpp;
            for(int j=0;j<n;j++){
                if(i==j) continue;    
                
                int dx1=points[i][0]-points[j][0];
                int dy1=points[i][1]-points[j][1];
                int d1=dx1*dx1+dy1*dy1;

                cnt+=2*mpp[d1];
                mpp[d1]++;
                
            }
        }
        return cnt;
    }
};