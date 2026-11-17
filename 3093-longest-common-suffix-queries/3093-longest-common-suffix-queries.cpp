class Node{
public:
    map<char,Node*>links;
    int idx=-1;
    int len=1e9;
    bool end=false;

    bool containsKey(char ch){
        return links.find(ch)!=links.end();
    }

    void put(char ch,Node* node){
        links[ch]=node;
    }

    Node* get(char ch){
        return links[ch];
    }

    bool isEnd(){
        return end;
    }

    void setEnd(){
        end=true;
    }
};

class Trie{
public:
    Node* root;
    
    Trie(){
        root=new Node();
    }

    void insert(string &word,int idx){
        if(root->len>word.size()){
            root->len = word.size();
            root->idx = idx;
        }else if(root->len == word.size()){
            root->idx = min(root->idx,idx);
        }

        Node* temp=root;

        for(int i=word.size();i>=0;i--){
            if(!temp->containsKey(word[i])){
                temp->put(word[i],new Node());
            }

            temp=temp->get(word[i]);

            if(temp->len>word.size()){
                temp->len=word.size();
                temp->idx=idx;
            }else if(temp->len==word.size()){
                temp->idx=min(temp->idx,idx);
            }
        }
        temp->setEnd();
    }

    bool prefix(string &word){
        Node* temp=root;
        for(int i=word.size();i>=0;i--){
            if(!temp->containsKey(word[i])) return false;
            temp=temp->get(word[i]);
        }
        return true;
    }

    int query(string word){
        Node* temp=root;
        for(int i=word.size();i>=0;i--){
            if(!temp->containsKey(word[i])) break;
            temp=temp->get(word[i]);
        }
        return temp->idx;
    }
};


class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie T;
        int i=0;
        for(string &word:wordsContainer){
            T.insert(word,i);
            i++;
        }

        vector<int>ans;

        for(string &word:wordsQuery){
            ans.emplace_back(T.query(word));
        }
        return ans;
    }
};