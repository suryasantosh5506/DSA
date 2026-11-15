class Solution {
public:

    int getx(string &s){
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
           if(s[i]=='x'){
                int ori=i;
                i--;
                string num="";
                while(i>=0 && s[i]!='+' && s[i]!='-'){
                    num+=s[i];
                    i--;
                }
                reverse(num.begin(),num.end());
                int coefficient=num.empty()?1:stoi(num);
                if(i>=0){
                    ans+=(s[i]=='+')?coefficient:-coefficient;
                }else ans+=coefficient;
                i=ori;
            }
        }
        return ans;
    }

    int getnumber(int &i,string &s){
        int n=s.size();
        string num="";
        while(i<n && isdigit(s[i])) num+=s[i++];
        return stoi(num);
    }

    int getvalue(string &s){
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;){
            if(isdigit(s[i])){
                char sign=(i-1>=0 && s[i-1]=='-')?'-':'+';
                int num=getnumber(i,s);
                if(i<n && s[i]=='x') continue;
                ans+=(sign=='+')?num:-num;
            }else i++;
        }
        return ans;
    }

    string solveEquation(string equation) {
        stringstream ss(equation);
        string lhs,rhs;
        getline(ss,lhs,'=');
        getline(ss,rhs);
        int leftx=getx(lhs);
        int rightx=getx(rhs);
        int leftvalue=getvalue(lhs);
        int rightvalue=getvalue(rhs);
        int coeff=leftx-rightx;
        int value=rightvalue-leftvalue;
        if(coeff==0 && value==0) return "Infinite solutions";
        if(coeff==0) return "No solution";
        return "x="+to_string(value/coeff);
    }
};