class Solution {
public:

    int n;

    void merge(int low,int mid,int high,vector<int>&arr){
        int i=low,j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]) temp.emplace_back(arr[i++]);
            else temp.emplace_back(arr[j++]);
        }

        while(i<=mid) temp.emplace_back(arr[i++]);
        while(j<=high) temp.emplace_back(arr[j++]);

        for(int i=0;i<temp.size();i++){
            arr[i+low]=temp[i];
        }
    }

    int count(int low,int mid,int high,vector<int>&arr){
        int ans=0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<=high && arr[i]>2ll*arr[j]) j++;
            ans+=j-(mid+1);
        }
        return ans;
    }

    int divide(int low,int high,vector<int>&nums){
        if(low>=high) return 0;
        int ans=0;
        int mid=low+(high-low)/2;
        ans+=divide(low,mid,nums);
        ans+=divide(mid+1,high,nums);
        ans+=count(low,mid,high,nums);
        merge(low,mid,high,nums);
        return ans;
    }

    int reversePairs(vector<int>& nums) {
        n=nums.size();
        return divide(0,n-1,nums);
    }
};