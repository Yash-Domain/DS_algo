// brute force 
class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.length();
        int min_penalty = INT_MAX;
        int earlies_hour = -1;

        for(int i = 0 ; i <= n ; i++){
            string open = s.substr(0,i);
            string close  = s.substr(i);
            int curr_penalty = 0;

            for(char &ch : close){
                if(ch == 'Y') curr_penalty++;
            }

            for(char &ch : open){
                if(ch == 'N') curr_penalty++;
            }

           // min_penalty = min(min_penalty,curr_penalty);
           if(curr_penalty < min_penalty){
                min_penalty = curr_penalty;
                earlies_hour = i;
           }
        }

        return earlies_hour;
    }
};
// optimal 
class Solution {
public:
    int bestClosingTime(string s) {
        int n = s.length();
        int min_penalty = INT_MAX;
        int earlies_hour = -1;

        vector<int>temp(n+1);

        int zeroth_count = 0;
        for(char ch : s){
            if(ch == 'Y'){
                zeroth_count++;
            }
        }

        temp[0] = zeroth_count;

        for(int i = 1 ; i <= n  ; i++){
            if(s[i-1] == 'N'){
                temp[i] = temp[i-1] + 1;
            }else{
                temp[i] = temp[i-1] - 1;
            }
        }

        for(int i = 0 ; i <= n ; i++){
            int curr_penalty = temp[i];

            if(curr_penalty < min_penalty){
                min_penalty = curr_penalty;
                earlies_hour = i;
            }
        }
        return earlies_hour;
    }
};