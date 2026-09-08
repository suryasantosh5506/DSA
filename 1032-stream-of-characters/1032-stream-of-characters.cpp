class Node{
public:
    Node* links[26]={nullptr};
    bool end=false;

    bool containsKey(char ch){
        return links[ch-'a']!=nullptr;
    }

    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    Node* next(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        end=true;
    }

    bool isEnd(){
        return end;
    }
};

class Trie{
public:
    Node* root;

    Trie(){
        root=new Node();
    }

    void insert(string &s){
        int n=s.size();
        Node* temp=root;
        for(int i=n-1;i>=0;i--){
            if(!temp->containsKey(s[i])){
                temp->put(s[i],new Node());
            }
            temp=temp->next(s[i]);
        }
        temp->setEnd();
    }

    bool startswith(string &s){
        int n=s.size();
        Node* temp=root;
        int i=n-1;
        for(;i>=0;i--){
            if(!temp->containsKey(s[i])) return false;
            temp=temp->next(s[i]);
            if(temp->isEnd()) return true;
        }
        return false;
    }
};

class StreamChecker {
public:

    Trie t;
    string stream;

    StreamChecker(vector<string>& words) {
        for(string &word:words) t.insert(word);
    }
    
    bool query(char letter) {
        stream+=letter;
        return t.startswith(stream);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */