class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int m=s.size();
        vector<int>ans(m);

        for(int i=0;i<m;i++){
            int cnt=0;
            int x=startPos[0],y=startPos[1];
            for(int j=i;j<m;j++){
                if(s[j]=='L') y--;
                else if(s[j]=='R') y++;
                else if(s[j]=='U') x--;
                else x++;

                if(x>=0 && x<n && y>=0 && y<n) cnt++;
                else break;
            }
            ans[i]=cnt;
        }
        return ans;
    }
};