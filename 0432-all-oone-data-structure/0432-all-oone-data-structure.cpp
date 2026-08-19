class AllOne {
public:

    map<string,int>mpp;
    map<int,unordered_set<string>>freqmap;

    AllOne() {
        
    }
    
    void inc(string key) {
        freqmap[mpp[key]].erase(key);
        if(freqmap[mpp[key]].empty()) freqmap.erase(mpp[key]);
        mpp[key]++;
        freqmap[mpp[key]].insert(key);
    }
    
    void dec(string key) {
        if(!mpp.count(key)) return;
        freqmap[mpp[key]].erase(key);
        if(freqmap[mpp[key]].empty()) freqmap.erase(mpp[key]);
        mpp[key]--;
        if(mpp[key]==0) mpp.erase(key);
        else freqmap[mpp[key]].insert(key);
    }
    
    string getMaxKey() {
        if(mpp.empty()) return "";
        return *freqmap.rbegin()->second.begin();
    }
    
    string getMinKey() {
        if(mpp.empty()) return "";
        return *freqmap.begin()->second.begin();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */