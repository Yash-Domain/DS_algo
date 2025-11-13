class Solution {
public:
    typedef tuple<int,int,int>t;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n , vector<int>(m,1e9));
        priority_queue<t,vector<t>,greater<t>>pq;
        pq.push({0,0,0}); //diff , i , j
        dist[0][0] = 0;

        int drow[] = {-1 , 0 , 1 , 0};
        int dcol[] = {0 , -1, 0 , 1};
        while(!pq.empty()){
            auto[diff,r,c] = pq.top();
            pq.pop();
            if(r == n-1 && c == m-1) return diff;
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow < n && nrow >= 0 && ncol >= 0 && ncol < m){
                    int effort = max(abs(heights[nrow][ncol] - heights[r][c]),diff);
                    if(effort < dist[nrow][ncol]){
                        dist[nrow][ncol] = effort;
                        pq.push({effort , nrow ,ncol});
                    }
                }     
            }
        } 
        return -1;
    }
};