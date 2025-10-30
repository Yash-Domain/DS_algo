class Solution {
  public:
    vector<string> ans;
    void solve(int ind , int n , string s){

        if(ind == n){
            ans.push_back(s);
            return ;
        }
        s.push_back('0');
        solve(ind + 1 ,n , s );
        s.pop_back();
        
        s.push_back('1');
        solve(ind + 1 , n ,s );
    }
  
    vector<string> binstr(int n) {
        // code here
        solve(0,n,"");
        return ans;
    }
};