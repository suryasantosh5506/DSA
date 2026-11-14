class Solution {
public:

    bool isprime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++) if(n%i==0) return false;
        return true;
    }

    bool completePrime(int num) {
        string s=to_string(num);
        int pre=0;

        for (char &c:s) {
            pre=pre*10+(c-'0');
            if (!isprime(pre)) return false;
        }

        for (int i=0;i<s.size();i++) {
            int suff=stoi(s.substr(i));
            if(!isprime(suff)) return false;
        }
        return true;   
    }
};