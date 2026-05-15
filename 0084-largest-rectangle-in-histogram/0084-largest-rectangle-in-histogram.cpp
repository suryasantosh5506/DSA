class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxi=0;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int nse=i;
                int ele=heights[st.top()];
                st.pop();
                int pse=(!st.empty())?st.top():-1;
                maxi=max(maxi,ele*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse=n;
            int ele=heights[st.top()];
            st.pop();
            int pse=(!st.empty())?st.top():-1;
            maxi=max(maxi,ele*(nse-pse-1));
        }
        return maxi;
    }
};