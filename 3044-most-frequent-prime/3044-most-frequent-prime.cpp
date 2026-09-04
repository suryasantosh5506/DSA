typedef long long ll;
class Solution {
public:

    int n,m;
    unordered_map<ll,int>freq;
    vector<int>dx={0,1,1,1,0,-1,-1,-1};
    vector<int>dy={1,1,0,-1,-1,-1,0,1};

    bool isValid(int i,int j){
        return (i>=0 && i<n) && (j>=0 && j<m);
    }

    bool isprime(ll n){
        if(n<=10) return false;

        for(ll i=2;1ll*i*i<=n;i++){
            if(n%i==0) return false;
        }
        return true;
    }

    void solution(int i,int j,ll num,vector<vector<int>>&mat){
        if(isprime(num)) freq[num]++;

        for(int k=0;k<8;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            ll curr=num;

            while(isValid(nr,nc)){
                curr=curr*10+mat[nr][nc];

                if(isprime(curr)) freq[curr]++;

                nr+=dx[k];
                nc+=dy[k];
            }
        }
    }

    int mostFrequentPrime(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();

        int maxi=0;
        ll ans=-1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solution(i,j,mat[i][j],mat);
            }
        }

        for(auto it:freq){
            if(it.second>maxi){
                maxi=it.second;
                ans=it.first;
            }else if(it.second==maxi && it.first>ans){
                ans=it.first;
            }
        }

        return ans;
    }
};