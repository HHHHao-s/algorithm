#include "../s.h"

class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(),tasks.end(), std::greater<int>());
        int n = processorTime.size();
        int high=0;
        for(int i=0;i<n;i++){
            high = max(high, processorTime[i]+tasks[i*4]);
        }
        return high;

    }
};