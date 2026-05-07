class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer>st=new HashSet<>();
        for(int x : banned){
            st.add(x);
        }

        int cnt=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(!st.contains(i)){
                if(sum+i>maxSum) break;
                cnt++;
                sum+=i;
            }
        }
        return cnt;
    }
}