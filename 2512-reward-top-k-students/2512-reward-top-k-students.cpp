class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string>positive(positive_feedback.begin(),positive_feedback.end());
        unordered_set<string>negative(negative_feedback.begin(),negative_feedback.end());
        unordered_map<int,int>mpp;
        // {id,score}
        int n=report.size();
        for(int i=0;i<n;i++){
            mpp[student_id[i]] = 0;
        }
        for(int i=0;i<n;i++){
            stringstream ss(report[i]);;
            string word;
            while(getline(ss,word,' ')){
                if(positive.count(word)) mpp[student_id[i]]+=3;
                if(negative.count(word)) mpp[student_id[i]]--;
            }
        }
        vector<vector<int>>temp;
        for(auto it:mpp){
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(),temp.end(),[](auto &a,auto &b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];
        });

        vector<int>ans;
        for(int i=0;i<min(int(temp.size()),k);i++){
            ans.emplace_back(temp[i][1]);
        }
        return ans;
    }
};