typedef long long ll;
class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        vector<int>pos,neg;
        bool haszero=false;

        for(int &x:nums){
            if(x>0) pos.emplace_back(x);
            else if(x<0) neg.emplace_back(x);
            else haszero=true;
        }

        sort(neg.begin(),neg.end());
        if(pos.size()==0 && neg.size()<=1){
            if(haszero) return 0;
            return neg[0];
        }

        ll pro=1;
        for(int x:pos) pro*=x;
        int n=neg.size();
        if(n%2==1) n--;

        for(int i=0;i<n;i++){
            pro*=neg[i];
        }
        return pro;
    }
};