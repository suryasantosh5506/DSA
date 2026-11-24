typedef long long ll;
class Solution {
public:

    double getdiscount(int discount,ll bill){
        return bill*((100-discount)/100.0);
    }

    string discountPrices(string sentence, int discount) {
        string ans="";
        string word="";
        int i=0;
        int n=sentence.size();
        while(i<n){
            if(sentence[i]==' '){
                i++;
                ans+=" ";
                continue;
            }
            if(sentence[i]=='$'){
                i++;
                bool isvalid=true;
                while(i<n && sentence[i]!=' '){
                    if(!isdigit(sentence[i])) isvalid=false;
                    word+=sentence[i];
                    i++;
                }
                if(isvalid && !word.empty()){
                    ll bill=stoll(word);
                    double final=getdiscount(discount,bill);
                    ostringstream ss;
                    ss << "$" << fixed << setprecision(2) << final;
                    ans += ss.str();
                }else{
                    ans+="$"+word;
                }
                word="";
            }else{
                while(i<n && sentence[i]!=' '){
                    word+=sentence[i];
                    i++;
                }
                ans+=word;
                word="";
            }
        }
        return ans;
    }
};