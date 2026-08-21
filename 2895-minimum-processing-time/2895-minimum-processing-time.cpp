class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.rbegin(),processorTime.rend());
        sort(tasks.begin(),tasks.end());

        int processors=processorTime.size();
        int taskcnt=tasks.size();

        int ans=0;

        for(int i=0;i<processors;i++){
            ans=max(ans,processorTime[i]+tasks[min(i*4+3,taskcnt-1)]);
        }
        return ans;
    }
};