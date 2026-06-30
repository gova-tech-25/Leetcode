class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin() , intervals.end());
        int cnt = 0;

        auto prev = intervals[0];
        for(int i = 1 ; i < n ; i++){
            auto curr = intervals[i];
            if(curr[0] < prev[1]){
                cnt++;
                    // Example: [1,5] vs [2,3].
                    // Carry forward [2,3] since it ends earlier and
                    // reduces the chance of future overlaps.
                    if(curr[1] < prev[1]) 
                    prev = curr;
            }
            else{
                prev = curr;
            }
        }
        return cnt;
    }
};