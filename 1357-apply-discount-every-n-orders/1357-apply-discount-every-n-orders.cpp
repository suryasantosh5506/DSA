class Cashier {
public:

    int cnt=0;
    int n;
    int discount;
    unordered_map<int,int>mpp;
    // {product,price};

    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n=n;
        this->discount=discount;
        for(int i=0;i<products.size();i++) mpp[products[i]]=prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        double bill=0;
        for(int i=0;i<product.size();i++){
            bill+=amount[i]*mpp[product[i]];
        }
        if(cnt%n==0) bill=bill*((100-discount)/100.0);
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */