class Node{
public:
    Node* links[26]={nullptr};
    bool end=false;

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
        }
        temp->setEnd();
    }
};

class Solution {
public:
    vector<int>dp;
    Trie T;

    int solution(int i,string &target){
        int n=target.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];

        Node* temp=T.head;
        int ans=1e8;
        for(int j=i;j<n;j++){
            if(!temp->containsKey(target[j])) break;
            temp=temp->getKey(target[j]);
            ans=min(ans,1+solution(j+1,target));
        }
        return dp[i]=ans;
    }

    int minValidStrings(vector<string>& words, string target) {
        for(string &x:words) T.insert(x);
        int n=target.size();
        dp.assign(n,-1);
        int ans=solution(0,target);
        return ans>=1e8?-1:ans;
    }
};