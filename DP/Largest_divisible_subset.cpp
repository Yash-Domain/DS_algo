class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>hash(n); 
        sort(arr.begin(),arr.end());
        int maxi = 0;
        int lastseen = 0;
        
        for(int i = 0 ; i < n ; i++){
            hash[i] = i;
            for(int j = 0 ; j < i ; j++){
                if(arr[i] % arr[j] == 0 && dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastseen = i;
            }
        }
        vector<int>temp;
        temp.push_back(arr[lastseen]);
        while(hash[lastseen] != lastseen){
            lastseen = hash[lastseen];
            temp.push_back(arr[lastseen]);
        }
        reverse(temp.begin(),temp.end());
        return temp; 
    }
};