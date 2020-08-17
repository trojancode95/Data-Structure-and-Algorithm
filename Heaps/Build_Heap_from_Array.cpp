//Build Heap from Array in:
//Method 1 : Time Complexity : O(NlogN)
//Method 2 : Time Complexity : O(N)


#include <bits/stdc++.h>
using namespace std;


void print(vector<int>v){
    for(int x:v)
    cout<<x<<" ";
    cout<<endl;
}

//Time Complexity : O(NlogN)
void buildHeap(vector<int>&v){
    for(int i=2;i<v.size();i++){
      int index=i;
      int parent=i/2;
      while(index>1 && v[index]>v[parent]){
        swap(v[index],v[parent]);
        index=parent;
        parent=parent/2;
      }
    }
}

bool compare(int a,int b){
  return a>b;
}
void heapify(vector<int>&v,int index){
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
    heapify(v,min_index);
  }
}

//Time Complexity : O(N)
void buildHeapOptimised(vector<int>&v){
    //We have to start from the first non leaf node
    for(int i=(v.size()-1)/2;i>=1;i--){
         heapify(v,i);
    }
}

int main(){

    //Zero index is blocked.We are building heap from index 1.
    vector<int>v{-1,10,20,5,6,1,8,9,4}; //Heap
    buildHeapOptimised(v);
    print(v);


     return 0;
}
