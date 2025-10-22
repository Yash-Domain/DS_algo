// insertion in heap
#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = -1;

    void insert(int x){
        size++;
        int index = size;
        arr[index] = x ;

        while( index > 0){
            int parent = (index-1)/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void deletefromheap(){
        if( size < 0 ) {
            cout<<"not possible";
        }

        arr[0] = arr[size];
        size--;

        int i = 0;
        while(i <= size){
            int lindex = 2*i+1;
            int rindex = 2*i+2;
            if(lindex <= size && arr[lindex] > arr[i] && arr[lindex] > arr[rindex]){
                swap(arr[i],arr[lindex]);
                i = lindex;
            }
            else if (rindex <= size && arr[rindex] > arr[i] && arr[rindex] > arr[lindex]){
                swap(arr[i],arr[rindex]);
                i = rindex;
            }
            else{
                return;
            }
        }
    }
    

    void print(){
        for(int i = 0 ; i <= size ; i++){
            cout<<arr[i]<<" ";
        }
    }
};
void heapify(int arr[],int n , int i){
        int largest = i;
        int lindex = 2*i+1;
        int rindex = 2*i+2;

        if(lindex < n && arr[lindex] > arr[largest]){
            largest = lindex;
        }
        if(rindex < n && arr[rindex] > arr[largest]){
            largest = rindex;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr,n,largest);
        }
    }

void heapSort(int arr[],int n){
    int size = n;
    while(size > 1){
        swap(arr[0],arr[n]);
        size--;
        heapify(arr,n,0);
    }
}

int main(){
    heap h;
    h.insert(4);
    h.insert(5);
    h.insert(8);
    h.insert(3);
    h.deletefromheap();
    //h.print();

    heap hp;
    int arr[5] = {54,53,55,52,50};
    int n = 5 ;
    for(int i = (n/2)-1 ; i >= 0 ; i--){
        heapify(arr,n,i);
    }
    for(int i = 0 ; i < n ; i++){
        cout << arr[i]<<" ";
    }
    cout<< endl;
    heapSort(arr,n);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i]<<" ";
    }
}