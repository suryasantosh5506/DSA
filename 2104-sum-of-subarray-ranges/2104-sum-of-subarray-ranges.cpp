typedef long long ll;
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

    ll sumSubarrayMins(vector<int>& arr) {
        n=arr.size();
        psee.resize(n);
        nse.resize(n);
        prevSmallEqual(arr);
        nextSmall(arr);
        ll ans=0;
        for(int i=0;i<n;i++){
            ans += 1LL * (i - psee[i]) * (nse[i] - i) * arr[i];
        }
        return ans;
    }


    vector<int>pgee;
    vector<int>nge;

    void prevGreatEqual(vector<int>&arr){
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            pgee[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
    }

    void nextGreat(vector<int>&arr){
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            nge[i]=(st.empty())?n:st.top();
            st.push(i);
        }
    }

    ll sumSubarrayMaxs(vector<int>& arr) {
        n=arr.size();
        pgee.resize(n);
        nge.resize(n);
        prevGreatEqual(arr);
        nextGreat(arr);
        ll ans=0;
        for(int i=0;i<n;i++){
            ans += 1LL * (i - pgee[i]) * (nge[i] - i) * arr[i];
        }
        return ans;
    }


    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};