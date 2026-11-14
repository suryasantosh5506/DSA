typedef long long ll;
class Solution {
public:

    bool solution(int i,ll prev,string curr,string &s){
        if(curr.size()>10){
            int leadingzeroes=0;
            for(char &x:curr){
                if(x=='0') leadingzeroes++;
                else break;
            }
            if(curr.size()-leadingzeroes>10) return false;
        }
        ll num=(curr.empty())?1e18:stoll(curr);
        if(i==s.size()){
            if(prev==-1) return false;
            if(num<=prev && prev-num==1) return true;
            return false;
        }

        bool ans=false;
        if((num<=prev && prev-num==1) || prev==-1){
            string next=string(1,s[i]);
            ans|=solution(i+1,num,next,s);
        }
        ans|=solution(i+1,prev,curr+s[i],s);

        return ans;
    }

    bool splitString(string s) {
        return solution(0,-1,"",s);
    }
};