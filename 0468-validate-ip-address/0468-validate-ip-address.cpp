class Solution {
public:

    bool validateipv4(vector<string>&arr){
        int n=arr.size();
        
        for(string &part:arr){
            if(part.empty() || part.size()>3) return false;
            if(part.size()>1 && part[0]=='0') return false;
            for(char &x:part){
                if(!isdigit(x)){
                    return false;
                }
            }
            int num=stoi(part);
            if(num<0 || num>255) return false;
        }
        return true;
    }

    bool validateipv6(vector<string>&arr){
        int n=arr.size();
        unordered_set<char>st={'a','b','c','d','e','f','A','B','C','D','E','F'};
        for(string &part:arr){
            if(part.empty() || part.size()>4) return false;
            for(char &x:part){
                if(!isdigit(x) && !st.count(x)){
                    return false;
                }
            }
        }
        return true;
    }

    bool validatepart(string &s){
        stringstream ss(s);
        string part="";
        vector<string>arr;
        while(getline(ss,part,':')) arr.emplace_back(part);
        return validateipv6(arr);
    }

    bool validatecompressedipv6(string &ip){
        int pos=ip.find("::");
        if(ip.find("::",pos+2)!=string::npos) return false;
        string firstpart=ip.substr(0,pos);
        string secondpart=ip.substr(pos+2);
        if (firstpart.size() + secondpart.size() >= 8) return false;
        if(!validatepart(firstpart)) return false;
        if(!validatepart(secondpart)) return false;
        return true;
    }

    string validIPAddress(string queryIP) {
        if(queryIP.empty() || queryIP == "::") return "Neither";
        vector<string>arr;
        stringstream ss(queryIP);
        string part="";

        if(queryIP.contains('.')){
            if(queryIP[0]=='.' || queryIP.back()=='.') return "Neither";
            while(getline(ss,part,'.')) arr.emplace_back(part);
            if(arr.size() != 4) return "Neither";
            if(validateipv4(arr)) return "IPv4";
        }else{
            bool compressed = queryIP.find("::") != string::npos;
            if(compressed){
                return "Neither";
            }else{
                if(queryIP[0]==':' || queryIP.back()==':') return "Neither";
                while(getline(ss,part,':')) arr.emplace_back(part);
                if(arr.size() != 8) return "Neither";
                if(validateipv6(arr)) return "IPv6";
            }
        }
        return "Neither";
    }
};