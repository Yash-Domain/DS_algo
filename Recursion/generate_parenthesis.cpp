// brute force 
class Solution {
public:
    vector<string> ans;
    bool isValid(string s){
        int count =0;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '(') count++;
            else count--;
            if(count < 0) return false;
        }
        return count==0;
    }

    void solve(int ind , int n , string s){
        if(ind == 2*n){
            if(isValid(s)){
            ans.push_back(s);
            }
            return;
        }
        s.push_back('(');
        solve(ind+1,n,s);

        s.pop_back();

        s.push_back(')');
        solve(ind+1,n,s);
    }

    vector<string> generateParenthesis(int n) {
        solve(0,n,"");
        return ans;
    }
};

// optimal 
class Solution {
public:
    vector<string> ans;
    void solve(int ind , int n , string s , int open , int close){
        if(ind == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
        s.push_back('(');
        solve(ind+1,n,s,open + 1,close);
        s.pop_back();
        }
        if(open > close){
        s.push_back(')');
        solve(ind+1,n,s,open,close+1);
        }
    }

    vector<string> generateParenthesis(int n) {
        int open = 0 , close = 0;
        solve(0,n,"",0,0);
        return ans;
    }
};