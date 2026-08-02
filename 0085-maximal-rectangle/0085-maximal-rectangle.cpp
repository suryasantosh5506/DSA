class Solution {
public:

    int solution(vector<int>& heights) {
        int ans=0;
        stack<int>st;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int ele=heights[st.top()];
                st.pop();
                int nse=i;
                int pse=(st.empty())?-1:st.top();
                ans=max(ans,ele*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int ele=heights[st.top()];
            st.pop();
            int nse=n;
            int pse=(st.empty())?-1:st.top();
            ans=max(ans,ele*(nse-pse-1));
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>arr(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            int ele=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1') ele++;
                else ele=0;
                arr[i][j]=ele;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,solution(arr[i]));
        }
        return ans;
    }
};