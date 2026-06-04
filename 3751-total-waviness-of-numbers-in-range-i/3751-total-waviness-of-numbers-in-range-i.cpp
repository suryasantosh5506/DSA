class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int waviness=0;
        if(num1<100 && num2<100) return 0;
        for(int i=num1;i<=num2;i++){
            string num=to_string(i);
            int n=num.size();
            
            for(int j=1;j<n-1;j++){
                int curr=num[j]-'0';
                int prev=num[j-1]-'0';
                int next=num[j+1]-'0';
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
};