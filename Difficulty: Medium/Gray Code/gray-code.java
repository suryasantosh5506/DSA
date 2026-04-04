class Solution {
    public ArrayList<String> graycode(int n) {
        // code here
        int total=1<<n;
        ArrayList<String>ans=new ArrayList<>();
        
        for(int i=0;i<total;i++){
            StringBuilder seq=new StringBuilder();
            int gray = i ^ (i >> 1);
            for(int j=n-1;j>=0;j--){
                seq.append((((gray >> j) & 1) == 1) ? '1' : '0');
            }
            ans.add(seq.toString());
        }
        return ans;
    }
}
