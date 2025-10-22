
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i = 0 ; i <= n/2 -1 ; i++){
            int l = 2*i+1;
            int r = 2*i+2;
            
            if(l < n && arr[l] > arr[i] ) return false;
            if(r < n && arr[r] > arr[i])  return false;
        } 
        return true;
    }
};