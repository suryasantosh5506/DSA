class Solution {
public:

    int solution(vector<int>&arr){
        int n=arr.size();
        int maxi=0;
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int nse=i;
                int ele=arr[st.top()];
                st.pop();
                int pse=(st.empty())?-1:st.top();
                maxi=max(maxi,ele*(nse-pse-1));
            }
            st.push(i);
        }
                
        while(!st.empty()){
            int nse=n;
            int ele=arr[st.top()];
            st.pop();
            int pse=(st.empty())?-1:st.top();
            maxi=max(maxi,ele*(nse-pse-1));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>arr(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                if(matrix[i][j]=='1') sum++;
                else sum=0;
                arr[i][j]=sum;
            }
        }

        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,solution(arr[i]));
        }
        return maxi;
    }
};