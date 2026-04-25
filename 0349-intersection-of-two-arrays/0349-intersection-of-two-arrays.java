class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        List<Integer>ans=new ArrayList<>();
        int n=nums1.length,m=nums2.length;
        int i=0,j=0;
        while(i<n&&j<m){
            if(nums1[i]==nums2[j]){
                if(ans.isEmpty()){
                    ans.add(nums1[i]);
                }
                else if(ans.get(ans.size()-1)!=nums1[i]){
                    ans.add(nums1[i]);
                }
                i++;
                j++;
            }else if(nums1[i]<nums2[j]) i++;
            else j++;
        }
        int[] res = new int[ans.size()];
        for (int k = 0; k < ans.size(); k++) {
            res[k] = ans.get(k);
        }
        return res;
    }
}