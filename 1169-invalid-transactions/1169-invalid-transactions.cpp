class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string>names,cities;
        vector<int>time,amount;
        int n=transactions.size();
        for(string &x:transactions){
            string name;
            stringstream ss(x);
            getline(ss,name,',');
            names.emplace_back(name);
            string t;
            getline(ss,t,',');
            time.emplace_back(stoi(t));
            string a;
            getline(ss,a,',');
            amount.emplace_back(stoi(a));
            string city;
            getline(ss,city,',');
            cities.emplace_back(city);
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            bool invalid=amount[i]>1000;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(cities[i]==cities[j]) continue;
                if(names[i]!=names[j]) continue;
                if(abs(time[i]-time[j])>60) continue;
                invalid=true;
                break;
            }
            if(invalid) ans.emplace_back(transactions[i]);
        }
        return ans;
    }
};