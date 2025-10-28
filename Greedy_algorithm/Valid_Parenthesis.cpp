// TC  O(3^N) recurssion
class Solution {
public:
    bool helper(string s , int ind , int count){
        if(count < 0) return false;
        if(ind == s.size()) return count == 0;
        if(s[ind] == '(') return helper(s,ind +1 , count +1);
        if(s[ind] == ')') return helper(s ,ind +1 , count - 1);
        return helper(s,ind +1 , count +1) || helper(s,ind +1 , count) || helper(s,ind +1 , count -1);
    }

    bool checkValidString(string s) {
        return helper(s,0,0);
    }
};

// optimal with min max O(N);
class Solution {
public:
    bool checkValidString(string s) {
        int max = 0 , min = 0 ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                max++;
                min++;
            }
            else if (s[i] == ')'){
                max--;
                min--;
            }
            else { // (*)
                max++;
                min--;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
        }
        return min == 0;
    }
};
