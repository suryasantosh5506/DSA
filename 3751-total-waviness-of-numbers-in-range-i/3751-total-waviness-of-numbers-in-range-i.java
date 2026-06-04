class Solution {
    public int totalWaviness(int num1, int num2) {
        int waviness=0;
        if(num1<100 && num2<100) return 0;
        for(int i=num1;i<=num2;i++){
            String num=Integer.toString(i);
            int n=num.length();
            
            for(int j=1;j<n-1;j++){
                int curr=num.charAt(j)-'0';
                int prev=num.charAt(j-1)-'0';
                int next=num.charAt(j+1)-'0';
                if(prev < curr && curr > next){
                    waviness++;
                }
                if(prev > curr && curr <next){
                    waviness++;
                }
            }
        }
        return waviness;
    }
}