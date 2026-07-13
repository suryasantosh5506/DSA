class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        string seq="123456789";

        for(int len=2;len<=9;len++){
            for(int start=0;start+len<=9;start++){
                int num=stoi(seq.substr(start,len));
                if(num>=low && num<=high) ans.emplace_back(num);
            }
        }
        return ans;
    }
};