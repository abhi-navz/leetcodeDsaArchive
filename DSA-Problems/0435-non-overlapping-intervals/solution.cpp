class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();
        // sorting intevals in ascending order of end time.
        sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b){
            return a[1]< b[1];
        });

        int count = 1;
        int lastEnd = intervals[0][1];

        for(int i = 1; i<n; i++){

            if(intervals[i][0] >= lastEnd){
                count++;
                lastEnd = intervals[i][1];
            }
        }

        return n - count;
        
    }
};
