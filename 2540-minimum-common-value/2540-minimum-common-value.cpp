class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int common=INT_MAX;
        int n=nums1.size(),m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                common=min(common,nums1[i]);
                i++;
                j++;
            }else if(nums1[i]>nums2[j]) j++;
            else i++;
        }
        return (common==INT_MAX)?-1:common;
    }
};