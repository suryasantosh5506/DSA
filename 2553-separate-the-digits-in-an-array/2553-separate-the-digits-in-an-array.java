class Solution {
    public int[] separateDigits(int[] nums) {
        List<Integer>ans=new ArrayList<>();
        for(int x:nums){
            String str=Integer.toString(x);
            for(int ch:str.toCharArray()){
                ans.add(ch-'0');
            }
        }

        int a[]=new int[ans.size()];

        for(int i=0;i<ans.size();i++){
            a[i]=ans.get(i);
        }

        return a;
    }
}