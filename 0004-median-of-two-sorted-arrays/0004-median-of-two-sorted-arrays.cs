public class Solution {
    public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
        int n=nums1.Length,m=nums2.Length;
        int total=n+m;
        int ind1=total/2;
        int ind2=ind1-1;
        int i=0,j=0;
        int ind=0;
        int ele1=-1,ele2=-1;

        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                if(ind==ind1) ele1=nums1[i];
                if(ind==ind2) ele2=nums1[i];
                i++;
                ind++;
            }else{
                if(ind==ind1) ele1=nums2[j];
                if(ind==ind2) ele2=nums2[j];
                j++;
                ind++;
            }
        }

        while(i<n){
            if(ind==ind1) ele1=nums1[i];
            if(ind==ind2) ele2=nums1[i];
            i++;
            ind++;
        }

        while(j<m){
            if(ind==ind1) ele1=nums2[j];
            if(ind==ind2) ele2=nums2[j];
            j++;
            ind++;
        }

        if(total%2==0) return (ele1+ele2)/2.0;
        return ele1;
    }
}