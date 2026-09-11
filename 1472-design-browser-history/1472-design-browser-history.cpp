class Node{
public:
    string val;
    Node* prev=nullptr;
    Node* next=nullptr;

    Node(string val){
        this->val=val;
    }
};


class BrowserHistory {
public:

    Node* head=nullptr;
    Node* curr;

    BrowserHistory(string homepage) {
        head=new Node(homepage);
        curr=head;
    }
    
    void visit(string url) {
        Node* newsite=new Node(url);
        curr->next=newsite;
        newsite->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(curr->prev!=nullptr && steps>0){
            curr=curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(curr->next!=nullptr && steps>0){
            curr=curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */