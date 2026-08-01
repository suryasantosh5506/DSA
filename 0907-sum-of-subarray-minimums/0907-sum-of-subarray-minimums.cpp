class Solution {
public:

    const int mod=1e9+7;
    vector<int>psee;
    int n;
    vector<int>nse;

    void prevSmallEqual(vector<int>&arr){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            psee[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
    }

    void nextSmall(vector<int>&arr){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            nse[i]=(st.empty())?n:st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        n=arr.size();
        psee.resize(n);
        nse.resize(n);
        prevSmallEqual(arr);
        nextSmall(arr);
        int ans=0;
        for(int i=0;i<n;i++){
            ans = (ans + ((i - psee[i]) * 1LL * (nse[i] - i) % mod * arr[i] % mod)) % mod;
        }
        return ans;
    }
};