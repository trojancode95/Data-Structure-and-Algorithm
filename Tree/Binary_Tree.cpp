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

node* buildTree(){
  int d;
  cin>>d;
  if(d==-1)
  return nullptr;
  node* root=new node(d);
  root->left=buildTree();
  root->right=buildTree();
  return root;
};

node* buildTreeLevelOrder() {
    int r;
    cin>>r;
    Node* root = new Node(r);
    queue<Node*>q;
    q.push(root);

    while(!q.empty()) {
        Node* child = q.front();
        q.pop();
        int a,b;
        cin>>a>>b;
        if(a!=-1) {
            child->left = new Node(a);
            q.push(child->left);
        }
        if(b!=-1) {
            child->right = new Node(b);
            q.push(child->right);
        }
    }
    return root;
}

void preOrder(node*root){
  if(root==nullptr)
  return;
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}
void inOrder(node* root){
  if(root==nullptr)
  return;
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

void postOrder(node* root){
  if(root==nullptr)
  return;
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}

//To print the particular nodes of Kth Level in Level Order Traversal
void printKthLevel(node*root,int k){
     if(root==nullptr)
     return;
     if(k==1){
       cout<<root->data<<" ";
       return;
     }
     printKthLevel(root->left,k-1);
     printKthLevel(root->right,k-1);
}


int height(node* root){
  if(root==nullptr)
  return 0;

  int leftHeight=height(root->left);
  int rightHeight=height(root->right);
  return 1+max(leftHeight,rightHeight);
}

//To print all Levels
void LevelOrderTraversal(node* root){
  int h = height(root);

  for(int i=1;i<=h;i++)
  printKthLevel(root,i);
}
//Level Order Traversal
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

// To get a newline after each Level Order Traversal (BFS2) using NULL Approach
void BFSNULL(node* root){
  queue<node*>q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    node* temp=q.front();
    if(temp==nullptr){
      cout<<endl;
      q.pop();
      if(!q.empty())
      q.push(nullptr);
    }
    else{
      cout<<temp->data<<" ";
      q.pop();
      if(temp->left)
      q.push(temp->left);
      if(temp->right)
      q.push(temp->right);
    }
  }
  return;
}

int countNodes(node*root){
  if(root==nullptr)
  return 0;

  return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumNodes(node* root){
  if(root==nullptr)
  return 0;

  return root->data + sumNodes(root->left) + sumNodes(root->right);
}
//O(n2) - Top_Bottom Approach
int diameter(node* root){
  if(root==nullptr)
  return 0;
  int h1=height(root->left);
  int h2=height(root->right);
  int opt1=h1+h2;
  int opt2=diameter(root->left);
  int opt3=diameter(root->right);
  return max(opt1,max(opt2,opt3));
}
class Pair{
public:
  int height;
  int diameter;
};


//O(n) - Bottom_Up Approach
Pair diameterOptimised(node* root){
  Pair p;
  if(root==nullptr){
    p.height=p.diameter=0;
    return p;
  }
  Pair left=diameterOptimised(root->left);
  Pair right=diameterOptimised(root->right);
  p.height=max(left.height,right.height)+1;
  p.diameter=max(left.height+right.height,max(left.diameter,right.diameter));
  return p;
}
//sum sumReplacement
int sumReplacement(node* root){
  if(root==NULL)
  return 0;

  if(root->left==NULL && root->right==NULL)
  return root->data;

  int leftsum=sumReplacement(root->left);
  int rightsum=sumReplacement(root->right);

  int temp=root->data;
  root->data=leftsum + rightsum;

  return temp+root->data;
}
class HBPair{
public:
  int height;
  bool balance;
};
HBPair isHeightBalance(node* root){
   HBPair p;
   if(root==nullptr){
     p.height=0;
     p.balance=true;
     return p;
   }
   HBPair left = isHeightBalance(root->left);
   HBPair right = isHeightBalance(root->right);

   p.height = max(left.height,right.height)+1;
   if(abs(left.height-right.height)<=1 && left.balance && right.balance)
   p.balance = true;
   else
   p.balance = false;
   return p;
}
//BUild Tree from Array
node* buildTreeFromArray(int *a,int s,int e){
   if(s>e)
   return nullptr;

   int mid=(s+e)/2;
   node *root=new node(a[mid]);
   root->left=buildTreeFromArray(a,s,mid-1);
   root->right=buildTreeFromArray(a,mid+1,e);
   return root;
}

//Create Tree from PreOrder and Inorder Traversal
node *createTreeFromInOrderTraversal(int *in,int *pre,int s,int e){
  static int i=0; //static variable initialise only once.It will not change its value and remains same the value last called in any function
  //base case
  if(s>e)
  return nullptr;

  node *root=new node(pre[i]);
  int index=-1;
  for(int j=s;j<=e;j++){
    if(in[j]==pre[i]){
      index=j;
      break;
    }
  }
  i++;
  root->left=createTreeFromInOrderTraversal(in,pre,s,index-1);
  root->right=createTreeFromInOrderTraversal(in,pre,index+1,e);
  return root;
}
//Right Side View of a Binary Tree
void rightSideView(node*root,int level){
  static int max_level=-1;
  if(root==nullptr)
  return;
  if(level>max_level){
    max_level=level;
    cout<<root->data<<" ";
  }
  rightSideView(root->right,level+1);
  rightSideView(root->left,level+1);
}
void topView(struct Node *root) {
	if(root==nullptr)
		return;
	map<int,int>m;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	while(!q.empty()){
		Node*temp=q.front().first;
		int h=q.front().second;
		q.pop();
		if(m.count(h)==0)
			m[h]=temp->data;
		if(temp->left)
			q.push({temp->left,h-1});
		if(temp->right)
			q.push({temp->right,h+1});
	}
	for(auto x:m)
		cout<<x.second<<" ";
}

void bottomView(struct Node *root) {
	if(root==nullptr)
		return;
	map<int,int>m;
	queue<pair<Node*,int>>q;
	q.push({root,0});
	while(!q.empty()){
		Node*temp=q.front().first;
		int h=q.front().second;
		q.pop();
		m[h]=temp->data;
		if(temp->left)
			q.push({temp->left,h-1});
		if(temp->right)
			q.push({temp->right,h+1});
	}
	for(auto x:m)
		cout<<x.second<<" ";
}

int main()
{
    node* root=buildTree();
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    cout<<height(root)<<endl;
    int k=height(root);
    printKthLevel(root,k);
    cout<<endl;
    LevelOrderTraversal(root);
    cout<<endl;
    BFS(root);
    cout<<endl;
    BFSNULL(root);
    cout<<countNodes(root)<<endl;
    cout<<sumNodes(root)<<endl;
    cout<<diameter(root)<<endl;
    Pair p=diameterOptimised(root);
    cout<<p.height<<" "<<p.diameter<<endl;

    HBPair q = isHeightBalance(root);
    if(q.balance)
    cout<<"It is a height balanced tree."<<endl;
    else
    cout<<"It is not a height balanced tree"<<endl;
    int a[]={1,2,3,4,5,6,7,8};
    node* newroot=buildTreeFromArray(a,0,7);
    BFS(newroot);
    cout<<endl;
    int in[]={3,2,8,4,1,6,7,5};
    int pre[]={1,2,3,4,8,5,6,7};
    node* r=createTreeFromInOrderTraversal(in,pre,0,7);
    BFS(r);
    cout<<endl;
    rightSideView(root,0);
    cout<<endl;

    return 0;
}
