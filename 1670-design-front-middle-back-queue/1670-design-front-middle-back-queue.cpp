class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class FrontMiddleBackQueue {
public:

    Node* front= nullptr;
    Node* back= nullptr;
    int len=0;

    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        Node* nNode=new Node(val);
        len++;
        if(front==nullptr){
            front=nNode;
            back=nNode;
            return;
        }else{
            nNode->next=front;
            front=nNode;
        }
    }
    
    void pushMiddle(int val) {
        if(len==0){
            pushFront(val);
            return;
        }
        int index=(len/2);
        if(index==0){
            pushFront(val);
            return;
        }
        Node* temp=front;
        for(int i=1;i<index;i++) temp=temp->next;
        Node* newNode=new Node(val);
        newNode->next=temp->next;
        temp->next=newNode;
        len++;
    }
    
    void pushBack(int val) {
        if(len==0){
            pushFront(val);
            return;
        }
        back->next=new Node(val);
        back=back->next;
        len++;
    }
    
    int popFront() {
        if(len==0) return -1;
        Node* temp=front;
        front=front->next;
        temp->next=nullptr;
        int val=temp->val;
        delete temp;
        len--;
        if(front==nullptr) back=nullptr;
        return val;
    }
    
    int popMiddle() {
        if(len==0) return -1;
        int tgt=(len-1)/2;
        if(tgt==0) return popFront();
        Node* temp=front;
        while(tgt>1){
            temp=temp->next;
            tgt--;
        }
        Node* dele=temp->next;
        int val=dele->val;
        temp->next=dele->next;
        len--;
        return val;
    }
    
    int popBack() {
        if(len==0) return -1;
        if(len==1) return popFront();
        Node* temp=front;
        while(temp->next && temp->next->next){
            temp=temp->next;
        }
        Node* dele=temp->next;
        int val=dele->val;
        temp->next=nullptr;
        delete dele;
        back=temp;
        if(back==nullptr) front=nullptr;
        len--;
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */