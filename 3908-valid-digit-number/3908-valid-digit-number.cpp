class Solution {
public:
    bool validDigit(int n, int x) {
        string num=to_string(n);
        return num[0]!=(x+'0') && num.find(x+'0')!=string::npos;
    }
};