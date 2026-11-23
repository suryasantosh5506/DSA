typedef long long ll;
class ProductOfNumbers {
public:

    vector<ll>arr;

    ProductOfNumbers() {
        arr.emplace_back(1);
    }
    
    void add(int num) {
        if(num==0){
            arr.clear();
            arr.emplace_back(1);
            return;
        }
        arr.emplace_back(1ll*arr.back()*num);
    }
    
    int getProduct(int k) {
        int n=arr.size();
        if(k>=n) return 0;
        return arr[n-1]/arr[n-(k+1)];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */