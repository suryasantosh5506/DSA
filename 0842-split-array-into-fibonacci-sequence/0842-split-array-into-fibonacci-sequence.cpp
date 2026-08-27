typedef long long ll;

class Solution {
public:

    vector<int>ans;
    int n;

    bool solution(int i,string num){
        if(i==num.size()) return (ans.size()>=3);

        int m=ans.size();
        for(int j=i;j<n;j++){
            string number=num.substr(i,j-i+1);
            if(number.size() > 1 && number[0]=='0') break;
            
            ll curr=stoll(number);
            if(curr>INT_MAX) break;

            if((ll)ans[m-1]+ans[m-2]==curr){
                ans.emplace_back(curr);
                if(solution(j+1,num)) return true;
                ans.pop_back();
            }
        }
        return false;
    }

    vector<int> splitIntoFibonacci(string num) {
        if(num.empty()) return ans;
        n=num.size();
        
        for(int i=0;i<n;i++){
            string first=num.substr(0,i+1);
            if(first.size()>1 && first[0]=='0') break;

            ll firstNum=stoll(first);
            if(firstNum>INT_MAX) break;

            ans.emplace_back(firstNum);

            for(int j=i+1;j<n;j++){
                string second=num.substr(i+1,j-i);
                if(second.size()>1 && second[0]=='0') break;

                ll secondNum=stoll(second);
                if(secondNum>INT_MAX) break;

                ans.emplace_back(secondNum);
                if(solution(j+1,num)) return ans;
                ans.pop_back();
            }
            ans.pop_back();
        }

        return ans;
    }
};