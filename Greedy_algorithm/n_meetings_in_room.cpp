class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int,int>> temp ;
        for(int i = 0 ; i < end.size() ; i++){
            temp.push_back({end[i] , start[i]});
        }
        sort(temp.begin() , temp.end());
        int count = 1 ;
        int last = temp[0].first;
        for(int i = 1 ; i < end.size() ; i++){
            if(temp[i].second > last){
                count ++ ;
                last = temp[i].first;
            }
        }
        return count ;
    }
};