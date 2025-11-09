// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        vector<string>onlevel;
        int level = 0 ; 
        queue<vector<string>> q; 
        q.push({beginWord});
        
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            
            if(vec.size() > level){
                level++;
                for(auto it : onlevel){
                    st.erase(it);
                }
            }
            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0){
                ans.push_back(vec);
                }
                else if(ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }
            
            for(int i = 0 ; i < word.length() ; i++){
                char original = word[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch ;
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        onlevel.push_back(word);
                        vec.pop_back();
                    }
                }
              word[i] = original;  
            }
        }
        return ans;
    }
};