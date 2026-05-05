class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
        vector<int>pse(n,-1);
        vector<int>nse(n,-1);
        stack<int>st1,st2;
        for(int i=0;i<n;i++){
            while(!st1.empty() && nums[st1.top()]>=nums[i]) st1.pop();
            pse[i]=(st1.empty())?-1:st1.top();
            st1.push(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && nums[st2.top()]>=nums[i]) st2.pop();;
            nse[i]=(st2.empty())?n:st2.top();
            st2.push(i);
        }

        for(auto x:pse){
            cout << x << " ";
        }
        cout << endl;

        for(auto x:nse){
            cout << x << " ";
        }
        cout << endl;

        for(int i=0;i<n;i++){
            double size = nse[i] - pse[i] - 1;
            double val=threshold/size;

            if(nums[i]>val){
                return size;
            }
        }

        return -1;
    }
};