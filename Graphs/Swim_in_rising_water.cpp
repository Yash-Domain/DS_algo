class Solution {
public:
    typedef tuple<int,int,int> p;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<p,vector<p>,greater<p>> pq;
        vector<vector<int>>vis(n,vector<int>(n,0));
        pq.push({grid[0][0], 0 , 0});
        while(!pq.empty()){
            auto [elevation , r , c] = pq.top();
            pq.pop();

            if(r == n-1 && c == n-1) return elevation;
            int drow[] = {-1,0,1,0};
            int dcol[] = {0,-1,0,1};
            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n 
                    && !vis[nrow][ncol] ){
                        vis[nrow][ncol] = 1;
                        pq.push({max(elevation , grid[nrow][ncol]) , nrow , ncol});
                    }
            }
        }
        return -1;
    }
};