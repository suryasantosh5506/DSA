class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>arr(nums1.begin(),nums1.begin()+m);
        int i=0,j=0;
        int index=0;

        while(i<m && j<n){
            if(arr[i]<nums2[j]) nums1[index]=arr[i++];
            else nums1[index]=nums2[j++];
            index++;
        }

        while(i<m) nums1[index++]=arr[i++];
        while(j<n) nums1[index++]=nums2[j++];
    }
};