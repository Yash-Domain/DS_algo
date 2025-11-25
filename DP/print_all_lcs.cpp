class Solution {
  public:
    vector<string> allLCS(string &s, string &t) {
        // Code here
        int n=s.size(), m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        LCS(dp,s,t);

        string ds=""; 
        /*st to store ds made by backtracking */
        set<string> st;  

       /*mp to know that state {i,j,ds} was previously visited or not*/

        unordered_map<string,bool> mp; 
        

        /* backtracking code for generating all possible  LCS */

        allLCS(dp,st,mp,s,t,n,m,ds); 
        
        vector<string> ans;
        for(auto i:st){
            reverse(i.begin(),i.end());
            ans.push_back(i);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
    void LCS(vector<vector<int>> &dp,string &s, string &t){
        int n=s.size(), m=t.size();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1]; 
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return;
    }
    void allLCS(vector<vector<int>> &dp,set<string> &st, 
                unordered_map<string,bool> &mp,string &s, 
                string &t,int i,int j,string &ds){
        if(i==0 || j==0){
            st.insert(ds);
            return;
        }
        string key = to_string(i)+'$'+to_string(j)+'$'+ds;
        if(mp.find(key)!=mp.end()) return;
        mp[key]=true;
        if(s[i-1]==t[j-1])
        {   
            /*
           if s[i-1]== t[j-1] then our dp[i][j] = 1+ dp[i-1][j-1] that is we have to include this letter for longest subsequence 
         */
            ds.push_back(s[i-1]);
            allLCS(dp,st,mp,s,t,i-1,j-1,ds);
            ds.pop_back();
        }
        else
        {
            /* if dp[i][j]==max(dp[i-1][j],dp[i][j-1]) so we might have come  to this state from dp[i-1][j] or dp[i][j-1] */

            if(dp[i][j]==dp[i-1][j]) allLCS(dp,st,mp,s,t,i-1,j,ds); 
            if(dp[i][j]==dp[i][j-1]) allLCS(dp,st,mp,s,t,i,j-1,ds);
        }
    }
};

