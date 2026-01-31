class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n - 1 ;
        char ans = letters[0];

        while(l <= r){
            int mid = l + (r - l)/2;
            if(letters[mid] > target){
                ans = letters[mid];
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }

        return ans;
    }
};