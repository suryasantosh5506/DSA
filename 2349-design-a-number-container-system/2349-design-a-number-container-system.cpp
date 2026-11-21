class NumberContainers {
public:

    unordered_map<int,int>indexes;
    // {index,number}
    unordered_map<int,set<int>>numbers;
    // {number,indexes}
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(indexes.count(index)){
            numbers[indexes[index]].erase(index);
        }
        indexes[index]=number;
        numbers[number].insert(index);
    }
    
    int find(int number) {
        if(!numbers.count(number) || numbers[number].size()==0) return -1;
        return *numbers[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */