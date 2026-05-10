class MyLinkedList {
public:

    ListNode* head=nullptr;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        for(ListNode* temp=head;temp!=nullptr;temp=temp->next){
            if(index==0) return temp->val;
            index--;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* newNode=new ListNode(val);
        newNode->next=head;
        head=newNode;
    }
    
    void addAtTail(int val) {
        if(head==nullptr){
            head=new ListNode(val);
            return;
        }
        ListNode* temp=head;
        for(;temp->next!=nullptr;temp=temp->next) continue;
        temp->next=new ListNode(val);
    }

    int getSize(){
        int cnt=0;
        for(ListNode* temp=head;temp!=nullptr;temp=temp->next) cnt++;
        return cnt;
    }
    
    void addAtIndex(int index, int val) {
        int size=getSize();
        if(index<0 || index>size) return;
        if(index==0) return addAtHead(val);

        if(index==size) return addAtTail(val);

        ListNode* temp=head;
        for(;temp!=nullptr;temp=temp->next){
            if(index==1){
                ListNode* newNode=new ListNode(val);
                newNode->next=temp->next;
                temp->next=newNode;
                break;
            }
            index--;
        }
    }
    
    void deleteAtIndex(int index) {
        if(head == nullptr) return;
        int size=getSize();

        if(index<0 || index>=size) return;

        if(index==0){
            ListNode* del=head;
            head=head->next;
            delete del;
            return;
        }

        if(size-1==index){
            ListNode* temp=head;
            for(;temp->next->next!=nullptr;temp=temp->next) continue;
            ListNode* del=temp->next;
            temp->next=nullptr;
            delete del;
            return;
        }

        ListNode* temp=head;
        for(;temp!=nullptr;temp=temp->next){
            if(index==1){
                ListNode* del=temp->next;
                temp->next=del->next;
                delete del;
                return;
            }
            index--;
        }        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */