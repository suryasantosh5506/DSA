class Solution {
public:

    string maskemail(string &s){
        stringstream ss(s);
        string name="",domain="";
        getline(ss,name,'@');
        getline(ss,domain);
        for(char &x:domain) x=tolower(x);
        return string(1,tolower(name[0]))+"*****"+string(1,tolower(name[name.size()-1]))+"@"+domain;
    }

    string maskphone(string &s){
        int digits=0;
        string number="";
        for(char &x:s){
            if(isdigit(x)){
                digits++;
                number+=x;
            }
        }
        if(digits==10) return "***-***-"+number.substr(6);
        if(digits==11) return "+*-***-***-"+number.substr(7);
        if(digits==12) return "+**-***-***-"+number.substr(8);
        return "+***-***-***-"+number.substr(9);
    }

    string maskPII(string s) {
        bool email=s.find('@')!=string::npos;
        return (email)? maskemail(s): maskphone(s);
    }
};