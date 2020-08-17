#include<bits/stdc++.h>
using namespace std;



class Node{
      public:
        char data;
        unordered_map<char,Node*>children;
        bool terminal;
        Node(char d){
          data=d;
          terminal=false;
        }
};

class Trie{

      Node* root;
      int cnt;

    public:

      Trie(){
        root=new Node('\0');
        cnt=0;
      }

      void insert(char *w){
        Node* temp=root;
        for(int i=0;w[i]!='\0';i++){
          char ch=w[i];
          if(temp->children.count(ch))//count check whether the character is present in the hashmap or not
          temp=temp->children[ch];
          else{
            Node* n=new Node(ch);
            temp->children[ch]=n;
            temp=n;
          }
        }
        temp->terminal=true;  //last character will always be terminal node
      }

      bool find(char* w){
        Node* temp=root;
        for(int i=0;w[i]!='\0';i++){
          char ch=w[i];
          if(temp->children.count(ch)==0)
          return false;
          else
          temp=temp->children[ch];
        }
        return temp->terminal;  // if the last character of any word which we r finding is terminal ,then that word is present, else it is only a prefix of any word.
      }
};

int main(){


      Trie t;
      char words[][10]={"a","hello","not","news","apple"};
      char w[10];
      cin>>w;
      for(int i=0;i<5;i++)
      t.insert(words[i]);

      if(t.find(w))
      cout<<w<<" is present"<<endl;
      else
      cout<<w<<" is not present"<<endl;


      return 0;
}
