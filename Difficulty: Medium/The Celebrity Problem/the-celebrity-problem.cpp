class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int start=0;
        int end=n-1;
        
        while(start<end){
            if(mat[start][end]==1) start++;
            else if(mat[end][start]==1) end--;
            else start++,end--;
        }
        
        for(int i=0;i<n;i++){
            if(i==start) continue;
            if(mat[i][start]==0 || mat[start][i]==1) return -1;
        }
        return start;
    }
};