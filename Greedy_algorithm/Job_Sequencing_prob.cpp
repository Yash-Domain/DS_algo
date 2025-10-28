class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        vector<pair<int,int>> temp;
        for(int i = 0 ; i < n ;i++){
            temp.push_back({profit[i],deadline[i]});
        }
        int max_deadline = 0 ;
        for(int i = 0 ; i < n ; i++ ){
            max_deadline = max(max_deadline, deadline[i]);
        }
        //int hash[max_deadline + 1] = {-1};
        vector<int>hash(max_deadline + 1, -1);
        int count = 0 ;
        int maxprofit = 0 ;
        sort(temp.begin() , temp.end() , greater<pair<int,int>>());
        for(int i = 0 ; i < n ; i++){
            for(int j = temp[i].second ; j > 0 ; j--){
                if(hash[j] == -1){
                    count ++ ;
                    maxprofit += temp[i].first;
                    hash[j] = temp[i].second;
                    break;
                }
            }
        }
        return {count,maxprofit};
    }
};