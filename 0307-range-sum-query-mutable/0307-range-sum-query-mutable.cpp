class SGTree{
    vector<int>segmentTree;
public:
    SGTree(int n){
        segmentTree.resize(4*n+1);
    }

    void build(int segmentIndex,int low,int high,vector<int>&arr){
        if(low==high){
            segmentTree[segmentIndex]=arr[low];
            return;
        }

        int mid=(low+high)/2;
        build(2*segmentIndex+1,low,mid,arr);
        build(2*segmentIndex+2,mid+1,high,arr);

        segmentTree[segmentIndex]=segmentTree[2*segmentIndex+1]+segmentTree[2*segmentIndex+2];
    }

    int query(int segmentIndex,int low,int high,int l,int r,vector<int>&arr){
        if(high<l || r<low) return 0;
        if(l<=low && high<=r) return segmentTree[segmentIndex];
        int mid=(low+high)/2;
        int left=query(2*segmentIndex+1,low,mid,l,r,arr);
        int right=query(2*segmentIndex+2,mid+1,high,l,r,arr);
        return left+right;
    }

    void update(int segmentIndex,int low,int high,int arrIndex,int updatedValue,vector<int>&arr){
        if(low==high){
            segmentTree[segmentIndex]=updatedValue;
            arr[arrIndex]=updatedValue;
            return;
        }
        int mid=(low+high)/2;
        if(arrIndex<=mid) update(2*segmentIndex+1,low,mid,arrIndex,updatedValue,arr);
        else update(2*segmentIndex+2,mid+1,high,arrIndex,updatedValue,arr);
        segmentTree[segmentIndex]=segmentTree[2*segmentIndex+1]+segmentTree[2*segmentIndex+2];
    }
};


class NumArray {
public:

    SGTree *segmentTree;
    vector<int>arr;
    int n;


    NumArray(vector<int>& nums) {
        n=nums.size();
        segmentTree=new SGTree(n);
        arr=nums;
        segmentTree->build(0,0,n-1,arr);
    }
    
    void update(int index, int val) {
        segmentTree->update(0,0,n-1,index,val,arr);
    }
    
    int sumRange(int left, int right) {
        return segmentTree->query(0,0,n-1,left,right,arr);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */