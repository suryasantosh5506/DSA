class Solution {
    public int[] executeInstructions(int n, int[] startPos, String s) {
        int m=s.length();
        int ans[]=new int[m];

        for(int i=0;i<m;i++){
            int cnt=0;
            int x=startPos[0],y=startPos[1];
            for(int j=i;j<m;j++){
                char ch=s.charAt(j);
                if(ch=='L') y--;
                else if(ch=='R') y++;
                else if(ch=='U') x--;
                else x++;

                if(x>=0 && x<n && y>=0 && y<n) cnt++;
                else break;
            }
            ans[i]=cnt;
        }
        return ans;
    }
}