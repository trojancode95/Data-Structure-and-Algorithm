//Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

class node{
public:
      int data;
      node*left;
      node*right;
      node(int d){
        data=d;
        left=NULL;
        right=NULL;
  }
};

//Accepts the old root node & data and returns the new root node
node* insertInBST(node*root , int data){
      //Base Case
      if(root==nullptr)
      return new node(data);

      //Recursive Case : Insert in the subtree and Update the Pointers
      if(data<=root->data)
      root->left=insertInBST(root->left,data);
      else
      root->right=insertInBST(root->right,data);

      return root;
}


node* buildBinarySearchTree(){
  //Read a list of numbers till -1 and also these numbers will be inserted into BST
      int d;
      cin>>d;
      node*root=nullptr;
      while(d!=-1){
        root=insertInBST(root,d);
        cin>>d;
      }
      return root;
};

//Searching a node in Binary Search Tree
bool SearchInBinarySearchTree(node*root , int data){
      if(root==nullptr)
      return false;

      if(root->data==data)
      return true;

      //Recursively search in left and the right subtree
      if(data < root->data)
      return SearchInBinarySearchTree(root->left,data);

      else
      return SearchInBinarySearchTree(root->right,data);

}


//Deleting a node in Binary Search Tree
node* deleteInBST(node*root,int data){
      if(root==nullptr)
      return nullptr;

      else if(data < root->data){
        root->left=deleteInBST(root->left,data);
        return root;
      }

      else if(data==root->data){
        //Found the node to delete in 3 Cases
        //Case 1. Node with  0 children
        if(root->left==nullptr && root->right==nullptr){
          delete root;
          return nullptr;
        }
        //Case 2. Node with 1 children
        if(root->left!=nullptr && root->right==nullptr){
          node*temp=root->left;
          delete root;
          return temp;
        }

        if(root->left==nullptr && root->right!=nullptr){
          node*temp=root->right;
          delete root;
          return temp;
        }

        //Case 3. Node with 2 children
          node*replace=root->right;
          //We find the Inorder Successor from right subtree
          while(replace->left!=nullptr)
          replace=replace->left;

          root->data=replace->data;
          root->right=deleteInBST(root->right,replace->data);
          return root;
      }

      else{
        root->right=deleteInBST(root->right,data);
        return root;
      }
}


//Check whether the given tree is BST or Not
//Top Down Approach
bool isCheckBST(node* root,int min=INT_MIN,int max=INT_MAX){
      if(root==nullptr)
      return true;

      if(root->data>=min && root->data<=max && isCheckBST(root->left,min,root->data) && isCheckBST(root->right,root->data,max))
      return true;
      else return false;
}
//Print the BST in Inorder root
//Inorder Traversal of Binary Search Tree gives sorted one.
void inOrder(node* root){
      if(root==nullptr)
      return;
      inOrder(root->left);
      cout<<root->data<<" ";
      inOrder(root->right);
}

//Print the BST Level By Level
void BFS(node* root){
      queue<node*>q;
      q.push(root);
      while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
      }
      return;
}

class LinkedList{
public:
      node*head;
      node*tail;
};

LinkedList flatten_a_BST(node* root){
    LinkedList l;
    if(root==nullptr){
      l.head=l.tail=nullptr;
      return l;
    }
    //Base Cases : Leaf Node
    if(root->left==nullptr && root->right==nullptr){
      l.head=l.tail=root;
      return l;
    }
    //Left is not NULL
    if(root->left!=nullptr && root->right==nullptr){
      LinkedList leftll=flatten_a_BST(root->left);
      leftll.tail->right=root;
      l.head=leftll.head;
      l.tail=root;
      return l;
    }
    //Right is not NULL
    if(root->left==nullptr && root->right!=nullptr){
      LinkedList rightll=flatten_a_BST(root->right);
      root->right=rightll.head;
      l.head=root;
      l.tail=rightll.tail;
      return l;
    }
    //Both sides are not NULL
    LinkedList leftll=flatten_a_BST(root->left);
    LinkedList rightll=flatten_a_BST(root->right);
    leftll.tail->right=root;
    root->right=rightll.head;
    l.head=leftll.head;
    l.tail=rightll.tail;
    return l;
}


int main()
{
    node*root=buildBinarySearchTree();

    inOrder(root);
    cout<<endl;

    BFS(root);
    cout<<endl;

    // int s;
    // cin>>s;
    // if(SearchInBinarySearchTree(root,s))
    // cout<<"Present"<<endl;
    // else
    // cout<<"Not Present"<<endl;
    //
    // int del;
    // cin>>del;
    // root=deleteInBST(root,del);
    // inOrder(root);
    // cout<<endl;

    if(isCheckBST(root))
    cout<<"The Given Binary Tree is BST"<<endl;
    else
    cout<<"The Given Binary Tree is not BST"<<endl;


    LinkedList l=flatten_a_BST(root);
    node* t=l.head;
    while(t){
      cout<<t->data<<"--->";
      t=t->right;
    }
    cout<<"NULL"<<endl;


    return 0;
}
