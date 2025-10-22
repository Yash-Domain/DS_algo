// User function Template for C++

class Solution {
  public:
    void Heapify(vector<int> & arr, int n , int i){
        int largest = i;
        int l = 2*i+1;
        int r = 2*i+2;
        
        if(l < n && arr[largest] < arr[l]) largest = l;
        if(r < n && arr[largest] < arr[r]) largest = r;
        
        if(largest != i){
            swap(arr[i],arr[largest]);
            Heapify(arr,n,largest);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int n) {
        for(int i = n/2 -1 ; i >=0 ; i--){
            Heapify(arr,n,i);
        }
    }
};
