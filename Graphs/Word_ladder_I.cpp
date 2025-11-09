class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            if (word == endWord)
                return level;

            for (int i = 0; i < word.length(); i++) {
                char ch = word[i]; 
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, level + 1});
                    }
                }
                word[i] = ch; // backtrack 
            }
        }
        return 0;
    }
};