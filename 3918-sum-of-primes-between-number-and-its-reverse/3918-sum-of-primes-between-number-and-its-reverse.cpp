class Solution {
public:
    
    vector<int>sieve;

    int solution(int start,int end){
        sieve.resize(1001);
        sieve[0]=sieve[1]=0;

        for(int i=2;i<=1000;i++){
            sieve[i]=i;
        }
        
        for(int i=2;i*i<=1000;i++){
            if(sieve[i]==i){
                for(int j=i*i;j<=1000;j+=i){
                    sieve[j]=i;
                }
            }
        }

        int ans=0;
            
        for(int i=start;i<=end;i++){
            if(sieve[i]==i) ans+=i;
        }

        return ans;
    }
    
    int sumOfPrimesInRange(int n) {
        string st=to_string(n);
        reverse(st.begin(),st.end());
        int r=stoi(st);
        int start=min(n,r);
        int end=max(n,r);
        return solution(start,end);
    }
};