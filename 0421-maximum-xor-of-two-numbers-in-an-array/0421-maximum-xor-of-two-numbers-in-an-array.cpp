class Node{
public:
    Node* links[2]={nullptr};

    void putKey(int bit,Node* node){
        links[bit]=node;
    }

    bool containsKey(int bit){
        return links[bit]!=nullptr;
    }

    Node* getKey(int bit){
        return links[bit];
    }
};

class Trie{
public:
    Node* head=nullptr;

    Trie(){
        head=new Node();
    }

    void insert(int n){
        Node* temp=head;
        for(int i=31;i>=0;i--){
            int bit=((n>>i)&1);
            if(!temp->containsKey(bit)) temp->putKey(bit,new Node());
            temp=temp->getKey(bit);
        }
    }

    int getMaxXor(int n){
        Node* temp=head;
        int ans=0;
        for(int i=31;i>=0;i--){
            int bit=((n>>i)&1);
            if(temp->containsKey(1-bit)){
                ans|=(1<<i);
                temp=temp->getKey(1-bit);
            }else{
                temp=temp->getKey(bit);
            }
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie T;
        for(int &x:nums) T.insert(x);
        int ans=0;
        for(int &x:nums) ans=max(ans,T.getMaxXor(x));
        return ans;
    }
};