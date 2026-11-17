class Node{
public:
    Node* links[26]={nullptr};
    bool end=false;
    int count=0;

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
            if(!temp->containsKey(x)) temp->putKey(x,new Node());
            temp=temp->getKey(x);
            temp->count++;
        }
    }

    int getCount(string &s){
        Node* temp=head;
        int ans=0;
        for(char &x:s){
            if(!temp->containsKey(x)) return ans;
            temp=temp->getKey(x);
            ans+=temp->count;
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie T;
        for(string &word:words) T.insert(word);
        int n=words.size();
        vector<int>ans;
        for(string &word:words) ans.emplace_back(T.getCount(word));
        return ans;
    }
};