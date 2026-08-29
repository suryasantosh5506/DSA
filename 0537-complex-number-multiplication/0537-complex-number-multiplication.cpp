class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        stringstream ss1(num1);
        stringstream ss2(num2);

        string word="";

        getline(ss1,word,'+');
        int real1=stoi(word);
        getline(ss2,word,'+');
        int real2=stoi(word);

        getline(ss1,word,'i');
        int ima1=stoi(word);
        getline(ss2,word,'i');
        int ima2=stoi(word);

        int real=(real1*real2)+(ima1*ima2*-1);
        int ima=(real1*ima2)+(real2*ima1);

        return to_string(real)+"+"+to_string(ima)+"i";
    }
};