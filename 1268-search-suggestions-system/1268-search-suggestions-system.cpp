class Node{
public:
    Node* links[26]={nullptr};
    bool end=false;
    set<string>words;

    void putKey(char ch,Node* node){
        links[ch-'a']=node;
    }

    Node* getKey(char ch){
        return links[ch-'a'];
    }

    bool containsKey(char ch){
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

    void insert(string &s){
        Node* temp=head;
        for(char &x:s){
            if(!temp->containsKey(x)){
                temp->putKey(x,new Node());
            }
            temp=temp->getKey(x);
            temp->words.insert(s);
        }
        temp->setEnd();
    }

    vector<string> getSuggestions(string &s){
        Node* temp=head;
        for(char &x:s){
            if(!temp->containsKey(x)){
                return {};
            }
            temp=temp->getKey(x);
        }
        vector<string>ans;
        int k=3;
        for(auto x:temp->words){
            if(k==0) break;
            ans.emplace_back(x);
            k--;
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        Trie T;
        for(string &s:products) T.insert(s);
        int n=searchWord.size();
        string word="";
        for(int i=0;i<n;i++){
            word+=searchWord[i];
            ans.emplace_back(T.getSuggestions(word));
        }
        return ans;
    }
};