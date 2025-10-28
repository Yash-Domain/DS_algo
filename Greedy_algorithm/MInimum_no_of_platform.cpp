class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin() , arr.end());
        sort(dep.begin() , dep.end());
        int maxcount = 0 ;
        int count = 0 , i = 0 , j = 0;
        while(i < arr.size()){
            if(arr[i] <= dep[j]){
                count++;
                i++;
            }
            else {
                count -- ;
                j++;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount ;
    }
};
