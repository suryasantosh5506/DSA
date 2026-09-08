typedef long long ll;
class ProductOfNumbers {
public:

    vector<ll>pro;

    ProductOfNumbers() {
        pro.emplace_back(1);
    }
    
    void add(int num) {
        if(num == 0) {
            pro.clear();
            pro.emplace_back(1);
            return;
        }
        
        int n=pro.size();
        pro.emplace_back(num*pro[n-1]);
    }
    
    int getProduct(int k) {
        int n=pro.size();

        if(k>=n) return 0;

        if(pro[n-k]==0) return 0;

        return pro[n-1]/pro[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */