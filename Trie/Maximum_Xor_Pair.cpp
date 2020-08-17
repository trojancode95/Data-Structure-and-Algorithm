Que : Maximum Xor pair in an array .
Solution:
Actually we can solve this problem using trie in O(32*N) where N is the number of elements in any array. Basically we can say , it is O(N).

Actually what we can do is to traversing the array from msb to lsb . for every element in array , if we r able to find its opposite bit in its msb part.then we are done with the solution part.


Below is the implementation of the code in CPP language.


#include<bits/stdc++.h>
using namespace std;

class trieNode{
public:
      trieNode* left; //Represents 0
      trieNode* right;//Represents 1
};

void insert(int n,trieNode* head){
      trieNode *curr=head;
      for(int i=31;i>=0;i--){
        int bit=(n>>i)&1;
        if(bit==0){
          if(curr->left==nullptr)
          curr->left=new trieNode();

          curr=curr->left;
        }
        else{
          if(curr->right==nullptr)
          curr->right=new trieNode();

          curr=curr->right;
        }
      }
}

int findMaxXorPair(trieNode* head,int ele){
        int max_xor=INT_MIN;
        trieNode *curr=head;
        int value=ele;
        int current_xor=0;
        for(int i=31;i>=0;i--){
          int bit=(value>>i)&1;
          if(bit==0){
            if(curr->right!=nullptr){
              curr=curr->right;
              current_xor+=(int)pow(2,i);
            }
            else
            curr=curr->left;
          }
          else{
            if(curr->left!=nullptr){
              curr=curr->left;
              current_xor+=(int)pow(2,i);
            }
            else
            curr=curr->right;
          }
        }
        max_xor=max(max_xor,current_xor);
        return max_xor;
}
int main(){
      int n;
      cin>>n;
      int *arr=new int[n]();
      for(int i=0;i<n;i++)
      cin>>arr[i];
      trieNode *head = new trieNode();

      int max_xor=INT_MIN;
      for(int i=0;i<n;i++){
        insert(arr[i],head);
        int x=findMaxXorPair(head,arr[i]);
        max_xor=max(max_xor,x);
      }
      cout<<max_xor<<endl;
      return 0;
}
