// O(N)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int hash[26] = {0};
        int ans = 0;
        for(char ch : tasks){
            hash[ch-'A']++;
        }

        for(int i = 0 ; i < 26 ; i++){
            if(hash[i] > 0){
            pq.push(hash[i]);
            }
        }

        while(!pq.empty()){
            vector<int> temp;
            for(int i = 0 ; i < n+1 ; i++){
                if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq);
                }
            }
            
            for( int f : temp){
                if(f > 0){
                    pq.push(f);
                }
            }
            
            if(!pq.empty()){
                ans += n+1;
            }
            else{
                ans += temp.size();
            }
        }
        return ans;
    }
};