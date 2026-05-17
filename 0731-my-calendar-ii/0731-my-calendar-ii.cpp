class Node{
public:
    int val;
    int lazy;
    Node* left;
    Node* right;

    Node(){
        val=0;
        lazy=0;
        left=nullptr;
        right=nullptr;
    }
};

class SGTree{
public:
    Node* root;
    SGTree(){
        root=new Node();
    }

    int query(Node* node,int low,int high,int l,int r){
        if(node->lazy!=0){
            node->val+=node->lazy;
            if(low!=high){
                if(!node->left) node->left=new Node();
                if(!node->right) node->right=new Node();

                node->left->lazy+=node->lazy;
                node->right->lazy+=node->lazy;
            }
            node->lazy=0;
        }

        //  l r low high or low high l r
        if(r<low || high<l) return 0;
        if(l<=low && high<=r) return node->val;
        int mid=low+(high-low)/2;
        int left=0,right=0;
        if(l<=mid && node->left)
            left=query(node->left,low,mid,l,r);

        if(r>mid && node->right)
            right=query(node->right,mid+1,high,l,r);
        return max(left,right);
    }

    void update(Node* node,int low,int high,int l,int r){
        if(node->lazy!=0){
            node->val+=node->lazy;
            if(low!=high){
                if(!node->left) node->left=new Node();
                if(!node->right) node->right=new Node();

                node->left->lazy+=node->lazy;
                node->right->lazy+=node->lazy;
            }
            node->lazy=0;
        }

        // l r low high or low high l r
        if(r<low || high<l) return;
        if(l<=low && high<=r){
            node->val++;
            if(low!=high){
                if(!node->left) node->left=new Node();
                if(!node->right) node->right=new Node();

                node->left->lazy++;
                node->right->lazy++;
            }
            return;
        }

        int mid=low+(high-low)/2;

        if(l<=mid){
            if(!node->left) node->left=new Node();
            update(node->left,low,mid,l,r);
        }
        if(r>mid){
            if(!node->right) node->right=new Node();
            update(node->right,mid+1,high,l,r);
        }

        int left=(node->left)?(node->left->val+node->left->lazy):0;
        int right=(node->right)?(node->right->val+node->right->lazy):0;
        node->val=max(left,right);
    }
};

class MyCalendarTwo {
public:
SGTree segmentTree;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        if(segmentTree.query(segmentTree.root,0,1e9,startTime,endTime-1)==2) return false;
        segmentTree.update(segmentTree.root,0,1e9,startTime,endTime-1);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */