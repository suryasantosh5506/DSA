class Node{
public:
    Node* links[27]={nullptr};
    bool end=false;
    int index=-1;

    void putKey(char ch,Node* node){
        links[ch-'a']=node;
    }

    void putSpecialKey(Node* node){
        links[26]=node;
    }

    Node* getKey(char ch){
        return (ch=='{')? links[26]:links[ch-'a'];
    }

    bool containsKey(char ch){
        if(ch=='{') return links[26]!=nullptr;
        return links[ch-'a']!=nullptr;
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
    Node* head=nullptr;
    Trie(){
        head=new Node();
    }

    void insert(string &s,int index){
        Node* temp=head;
        for(char &x:s){
            if(x == '{'){
                if(!temp->containsKey(x)) temp->putSpecialKey(new Node());
            }else if(!temp->containsKey(x)) temp->putKey(x,new Node());
            temp=temp->getKey(x);
            temp->index=index;
        }
        temp->setEnd();
    }

    int getindex(string &word){
        Node* temp=head;
        for(char &x:word){
            if(!temp->containsKey(x)) return -1;
            temp=temp->getKey(x);
        }
        return temp->index;
    }
};


class WordFilter {
public:

    Trie T;

    WordFilter(vector<string>& words) {
        int ind=0;
        for(string &str:words){
            for(int i=0;i<str.size();i++){
                string key=str.substr(i)+"{"+str;
                T.insert(key,ind);
            }
            ind++;
        }
    }
    
    int f(string pref, string suff) {
        string key=suff+"{"+pref;
        return T.getindex(key);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */ 