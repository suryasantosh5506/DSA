class CombinationIterator {
public:

    vector<string>arr;
    string seq="";
    int n;
    int index=0;

    void solution(int i,string s,int len){
        if(seq.size()==len){
            arr.emplace_back(seq);
            return;
        }
        if(i==n) return;

        seq+=s[i];
        solution(i+1,s,len);
        seq.pop_back();
        solution(i+1,s,len);
    }

    CombinationIterator(string characters, int combinationLength) {
        n=characters.size();
        solution(0,characters,combinationLength);
    }
    
    string next() {
        return arr[index++];
    }
    
    bool hasNext() {
        return index<arr.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */