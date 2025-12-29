// brute force if only no backtrack was possible 
class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();

        while (n > 1) {
            string next_bottom = "";

            for (int i = 0; i < n - 1; i++) {
                string pair = bottom.substr(i, 2);
                char top = '$';

                for (string& s : allowed) {
                    if (s.substr(0, 2) == pair) {
                        top = s[2];
                        next_bottom.push_back(top);
                        break;
                    }
                }
                if (top == '$')
                    return false;
            }
            bottom = next_bottom;
            n--;
        }
        return true;
    }
};
// optimal backtrack
class Solution {
public:
    unordered_map<string, bool> t; // memoization 

    bool solve(string curr, unordered_map<string, vector<char>>& mp, int ind, string above) {
        if (curr.length() == 1)
            return true;

        if (ind == curr.length() - 1) {
            return solve(above, mp, 0, "");
        }

        string key = curr + "_" + to_string(ind) + "_" + above;

        if (t.count(key)) {
            return t[key];
        }

        string pair = curr.substr(ind, 2);

        if (!mp.count(pair)) {
            return t[key] = false;
        }

        for (char& ch : mp[pair]) {
            above.push_back(ch);

            if (solve(curr, mp, ind + 1, above) == true) {
                return t[key] = true;
            }

            above.pop_back();
        }

        return t[key] = false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;

        for (string& s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }

        return solve(bottom, mp, 0, "");
    }
};