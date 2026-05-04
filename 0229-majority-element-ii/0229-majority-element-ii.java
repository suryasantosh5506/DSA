class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int ele1=Integer.MIN_VALUE,ele2=Integer.MIN_VALUE;
        int cnt1=0,cnt2=0;
        int n=nums.length;

        for(int x:nums){
            if(cnt1==0 && x!=ele2){
                ele1=x;
                cnt1++;
            }else if(cnt2==0 && x!=ele1){
                ele2=x;
                cnt2++;
            }else if(ele1==x) cnt1++;
            else if(ele2==x) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int x:nums){
            if(x==ele1) cnt1++;
            else if(x==ele2) cnt2++;
        }
        List<Integer>ans=new ArrayList<>();
        if(cnt1>n/3) ans.add(ele1);
        if(cnt2>n/3) ans.add(ele2);
        return ans;
    }
}