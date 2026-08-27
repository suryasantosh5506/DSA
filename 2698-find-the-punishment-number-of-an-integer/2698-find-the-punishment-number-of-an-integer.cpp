class Solution {
public:

    bool solution(int i,string &num,int tgt){
        if(i==num.size()) return (tgt==0);

        int number=0;
        for(int j=i;j<num.size();j++){
            number=(number*10)+(num[j]-'0');
            if(solution(j+1,num,tgt-number)) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            string num=to_string(i*i);
            if(solution(0,num,i)){
                ans+=(i*i);
            }
        }
        return ans;
    }
};