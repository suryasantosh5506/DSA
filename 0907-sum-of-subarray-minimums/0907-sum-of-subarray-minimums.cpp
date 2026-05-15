class Solution {
public:

    const int mod=1e9+7;

    vector<int> prevsmallestequalele(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[st.top()]>arr[i]) st.pop();
            ans[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        return ans;
    }

    
    vector<int> nextsmallestele(vector<int>&arr){
        int n=arr.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]) st.pop();
            ans[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int>psee=prevsmallestequalele(arr);
        vector<int>nse=nextsmallestele(arr);
        int n=arr.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans = (ans + ((i - psee[i]) * 1LL * (nse[i] - i) % mod * arr[i] % mod)) % mod;
        }
        return ans;
    }
};