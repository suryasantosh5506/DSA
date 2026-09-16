class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        int total=n+m;
        int ind1=total/2;
        int ind2=ind1-1;
        int ele1=-1,ele2=-1;
        int ind=0;
        int i=0,j=0;

        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                if(ind1==ind) ele1=nums1[i];
                if(ind2==ind) ele2=nums1[i];
                i++;
                ind++;
            }else{
                if(ind1==ind) ele1=nums2[j];
                if(ind2==ind) ele2=nums2[j];
                j++;
                ind++;
            }
        }

        while(i<n){
            if(ind1==ind) ele1=nums1[i];
            if(ind2==ind) ele2=nums1[i];
            i++;
            ind++;
        }

        while(j<m){
            if(ind1==ind) ele1=nums2[j];
            if(ind2==ind) ele2=nums2[j];
            j++;
            ind++;
        }

        if(total%2==1) return ele1;
        return (ele1+ele2)/2.0;
    }
};