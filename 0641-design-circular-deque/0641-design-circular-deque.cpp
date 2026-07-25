class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};

class MyCircularDeque {
public:
    Node* head=nullptr,*tail=nullptr;
    int k;
    int len;

    MyCircularDeque(int k) {
        this->k=k;
        len=k;  
    }
    
    bool insertFront(int value) {
        if(len<=0) return false;
        len--;
        Node* newNode=new Node(value);
        if(!head){
            head=tail=newNode;
            return true;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return true;
    }
    
    bool insertLast(int value) {
        if(len<=0) return false;
        len--;
        Node* newNode=new Node(value);
        if(!head){
            head=tail=newNode;
            return true;
        }
        tail->next=newNode;
        newNode->prev=tail;
        tail=newNode;
        return true;
    }
    
    bool deleteFront() {
        if(!head) return false;
        len++;
        if(head->next==nullptr){
            Node* del=head;
            head=tail=nullptr;
            delete del;
            return true;
        }
        Node* del=head;
        head=head->next;
        head->prev=nullptr;
        delete del;
        return true;
    }
    
    bool deleteLast() {
        if(!head) return false;
        len++;
        if(head->next==nullptr){
            Node* del=head;
            head=tail=nullptr;
            delete del;
            return true;
        }
        Node* del=tail;
        tail=tail->prev;
        tail->next=nullptr;
        delete del;
        return true;
    }
    
    int getFront() {
        if(!head) return -1;
        return head->val;
    }
    
    int getRear() {
        if(!head) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return head==nullptr;
    }
    
    bool isFull() {
        return len==0;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */