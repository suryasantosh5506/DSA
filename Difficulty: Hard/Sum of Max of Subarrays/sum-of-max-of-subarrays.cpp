class Solution {
  public:
  
    vector<int> prevGreatestEqualEle(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    
    vector<int> nextGreatestEle(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
  
    int sumOfMax(vector<int> &arr) {
        // code here
        vector<int>pgee=prevGreatestEqualEle(arr);
        vector<int>nge=nextGreatestEle(arr);
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            ans+=(i-pgee[i])*(nge[i]-i)*arr[i];
        }
        return ans;
    }
};