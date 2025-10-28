class Solution {
public:
    static bool mycomp(vector<int> &v1 , vector<int> &v2){
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end() , mycomp);
        int count = 1; 
        int last = intervals[0][1];
        int n = intervals.size();

        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] >= last){
                count ++ ;
                last = intervals[i][1];
            }
        }
        return n - count;
    }
};