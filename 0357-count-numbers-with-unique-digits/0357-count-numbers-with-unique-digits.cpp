class Solution {
public:

    vector<bool>used;

    int solution(string s,int n){
        if(s.size()>n) return 0;

        int ans=1;
        for(char ch='0';ch<='9';ch++){
            if(used[ch-'0']) continue;
            if(s.empty() && ch=='0') continue;
            used[ch-'0']=true;
            s+=ch;
            ans+=solution(s,n);
            s.pop_back();
            used[ch-'0']=false;
        }
        return ans;
    }

    int countNumbersWithUniqueDigits(int n) {
        used.resize(10,false);
        return solution("",n);
    }
};