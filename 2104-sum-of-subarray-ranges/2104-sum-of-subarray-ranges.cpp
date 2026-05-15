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

    long long subArrayMaxs(vector<int>&arr){
        vector<int>pgee=prevGreatestEqualEle(arr);
        vector<int>nge=nextGreatestEle(arr);
        int n=arr.size();
        long long total=0;
        for(int i=0;i<n;i++){
            total+=1ll*(i-pgee[i])*(nge[i]-i)*arr[i];
        }
        return total;
    }

    vector<int> prevSmallestEqualEle(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> nextSmallestEle(vector<int>&arr){
        int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }

    long long subArrayMins(vector<int>&arr){
        vector<int>psee=prevSmallestEqualEle(arr);
        vector<int>nse=nextSmallestEle(arr);
        int n=arr.size();
        long long total=0;
        for(int i=0;i<n;i++){
           total+=1ll*(i-psee[i])*1LL*(nse[i]-i)*arr[i];
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subArrayMaxs(nums)-subArrayMins(nums);
    }
};