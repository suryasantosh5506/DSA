class Solution {
public:
    bool checkString(string s) {
        char prev='a';
        for(auto x:s){
            if(x=='a' && prev=='b') return false;
            prev=x;
        }
        return true;
    }
};