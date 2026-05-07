class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int total=n+m;
        int ind1=total/2;
        int ind2=ind1-1;
        int i=0,j=0;
        int ele1=-1,ele2=-1;
        int cnt=0;

        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                if(cnt==ind1) ele1=nums1[i];
                if(cnt==ind2) ele2=nums1[i];
                i++;
                cnt++;
            }else{
                if(cnt==ind1) ele1=nums2[j];
                if(cnt==ind2) ele2=nums2[j];
                j++;
                cnt++;
            }
        }

        while(i<n){
            if(cnt==ind1) ele1=nums1[i];
            if(cnt==ind2) ele2=nums1[i];
            i++;
            cnt++;
        }

        while(j<m){
            if(cnt==ind1) ele1=nums2[j];
            if(cnt==ind2) ele2=nums2[j];
            j++;
            cnt++;
        }

        if(total%2==1) return ele1;
        return (ele1+ele2)/2.0;
    }
};