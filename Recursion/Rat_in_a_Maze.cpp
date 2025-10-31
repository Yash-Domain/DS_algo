class Solution {
  public:

    void solve(int i , int j ,vector<vector<int>>& maze ,vector<vector<int>> &visited,
    string path,int n,vector<string> &ans){
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        int di[] = {1 , 0 , 0 ,-1};
        int dj[] = {0 , -1 ,1 , 0};
        string dir="DLRU";
        for(int ind = 0 ; ind < 4 ; ind++){
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if(nexti < n && nexti >= 0 && nextj < n && nextj >= 0 
            && visited[nexti][nextj]==0 && maze[nexti][nextj]==1){
                visited[nexti][nextj] = 1;
                solve(nexti,nextj,maze,visited,path + dir[ind],n,ans);
                visited[nexti][nextj] = 0;
            }
        }
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> visited(n,vector<int>(n,0));
        if(maze[0][0] == 1) {
            visited[0][0] = 1;   
            solve(0,0,maze,visited,"",n,ans);
            }
       // sort(ans.begin(), ans.end());
        return ans;
    }
};