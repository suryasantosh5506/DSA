typedef long long ll;
class Solution {
public:

    bool isPrime(ll num){
        if(num<=1) return false;
        for(ll i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        int n=s.size();
        unordered_set<ll>st;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                st.insert(stoll(temp));
            }
        }

        priority_queue<ll,vector<ll>,greater<ll>>pq;

        for(ll x:st){
            if(isPrime(x)){
                pq.push(x);
                if(pq.size()>3) pq.pop();
            }
        }

        ll ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};