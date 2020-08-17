//Insertion Sort can be one of the soln but its time complexity is O(n square).


#include<bits/stdc++.h>
using namespace std;

void Median_of_a_stream(vector<int>&v,int n){
    //max heap to store the smaller half element
    priority_queue<int>s;
    //min heap to store the greater half element
    priority_queue<int,vector<int>,greater<int>>g;
    s.push(v[0]);
    double median=v[0];
    cout<<median<<endl;
    for(int i=1;i<n;i++){
      int x=v[i];
      // case1 : left side heap has more elements
      if(s.size()>g.size()){
        if(x<median){
          s.push(x);
          g.push(s.top());
          s.pop();
        }
        else
        g.push(x);

        median=(double)(s.top()+g.top())/2;
      }
      // case2 : both heaps are balanced
      else if(s.size()==g.size()){
        if(x<median){
          s.push(x);
          median=(double)s.top();
        }
        else{
          g.push(x);
          median=(double)g.top();
        }
      }
      // case3 : right side heap has more elements
      else{
        if(x<=median)
        s.push(x);
        else{
          g.push(x);
          s.push(g.top());
          g.pop();
        }
        median=(double)(s.top()+g.top())/2;
      }
      cout<<median<<endl;
    }
}


int main(){

    int n;
    cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];
    Median_of_a_stream(v,n);
}
