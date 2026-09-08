class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num==0) return true;
        for(int i=1;i<=num;i++){
            string ori=to_string(i);
            string rev=ori;
            reverse(rev.begin(),rev.end());
            if(stoi(rev)+stoi(ori)==num) return true;
        }
        return false;
    }
};