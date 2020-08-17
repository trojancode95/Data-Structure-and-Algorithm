#include<bits/stdc++.h>
using namespace std;

void downHeapify(vector<int>&heap,int idx){
    int leftIdx = 2*idx+1;
    int rightIdx = 2*idx+2;
    if(leftIdx>=heap.size() && rightIdx>=heap.size())
    return;

    int largestIdx=idx;
    if(leftIdx<heap.size() && heap[leftIdx]>heap[largestIdx])
    largestIdx=leftIdx;

    if(rightIdx<heap.size() && heap[rightIdx]>heap[largestIdx])
    largestIdx=rightIdx;

    if(largestIdx==idx)
    return;
    swap(heap[idx],heap[largestIdx]);
    downHeapify(heap,largestIdx);
}

void deletePeak(vector<int>&heap){
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    downHeapify(heap,0);
}

// void insert(vector<int>&heap,int key){
//     heap.push_back(key);
//     upheapify(heap,heap.size()-1);
// }

// void buildheap(vector<int>&heap){
//     for(int i=0;i<heap.size();i++)
//     upheapify(heap,i);
// }

void buildHeapOptimised(vector<int>&heap){
    for(int i=heap.size()-1;i>=0;i--)
    downHeapify(heap,i);
}

void display(vector<int>&heap){
    for(int i=0;i<heap.size();i++)
    cout<<heap[i]<<" ";
    cout<<"\n";
}


void downHeapifyHelper(vector<int>&heap,int idx,int heapSize){
    int leftIdx = 2*idx+1;
    int rightIdx = 2*idx+2;
    if(leftIdx>=heapSize && rightIdx>=heapSize)
    return;

    int largestIdx=idx;
    if(leftIdx<heapSize && heap[leftIdx]>heap[largestIdx])
    largestIdx=leftIdx;

    if(rightIdx<heapSize && heap[rightIdx]>heap[largestIdx])
    largestIdx=rightIdx;

    if(largestIdx==idx)
    return;
    swap(heap[idx],heap[largestIdx]);
    downHeapifyHelper(heap,largestIdx,heapSize);
}

void heapSort(vector<int>&arr){
    int heapSize=arr.size();
    buildHeapOptimised(arr);
    for(int i=arr.size()-1;i>=0;i--){
      swap(arr[0],arr[i]);
      heapSize--;
      downHeapifyHelper(arr,0,heapSize);
    }
}
int main(){

    int n;
    cin>>n;
    vector<int>heap(n);
    for(int i=0;i<n;i++)
    cin>>heap[i];

    heapSort(heap);
    display(heap);
    return 0;
}
