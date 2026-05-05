class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>ans(n);
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            
            while(pq.size()>k) pq.pop();
            if(pq.size()<k) ans[i]=-1;
            else ans[i]=pq.top();
        }
        return ans;
    }
};