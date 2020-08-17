// Heap or Priority Queue
// A Heap is a special Tree-based data structure in which the tree is a complete binary tree. Generally, Heaps can be of two types:
// Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.
// Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children. The same property must be recursively true for all sub-trees in that Binary Tree.


#include <bits/stdc++.h>
using namespace std;

class Heap{
    vector<int>v;
    bool minHeap;
    bool compare(int a,int b){
      if(minHeap)
      return a<b;
      else
      return a>b;
    }
    void heapify(int index){
      int left=2*index;
      int right=left+1;
      int min_index=index;
      int last_index=v.size()-1;

      if(left<=last_index && compare(v[left],v[index]))
      min_index=left;
      if(right<=last_index && compare(v[right],v[min_index]))
      min_index=right;

      //It means there is a smaller element
      //Also a Base Case if node comes at its correct position
      if(min_index!=index){
        swap(v[index],v[min_index]);
        heapify(min_index);
      }
    }
public:
    Heap(int default_size = 10, bool type = true){
      v.reserve(default_size);
      v.push_back(-1);
      minHeap = type;
    }

    //Implementing MinHeap as well as MaxHeap
    //Keep pushing to the top till you reach a root node or stop midway because current element is already greater than its parent node.
    void push(int d){
      v.push_back(d);
      int index=v.size()-1;
      int parent=index/2;
      while(index>1 && compare(v[index],v[parent])){
        swap(v[index],v[parent]);
        index=parent;
        parent=parent/2;
      }
    }
    //Return the topmost element of the Heap
    int top(){
      return v[1];
    }
    //Remove the min or max element from heap or we can say it removes the root node of the heap.
    void pop(){
      int last_index=v.size()-1;
      swap(v[1],v[last_index]);
      v.pop_back();
      //Heapify Operation
      heapify(1);//index/we want to heapify the index 1 or we can say that we can find the correct position of the index 1 in the heap
    }

    bool empty(){
      return v.size()==1;
    }
};

int main(){

     //Give some initial size of heap.
     //if the arguement is true ,then it will act as minHeap and if it is true, it behaves as MaxHeap
     Heap h(10,false);
     int n;
     cin>>n;
     for(int i=0;i<n;i++){
       int element;
       cin>>element;
       h.push(element);
     }
    while(!h.empty()){
      cout<<h.top()<<" ";
      h.pop();
    }
    cout<<endl;
     return 0;
}
