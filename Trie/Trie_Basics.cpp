#include<bits/stdc++.h>
using namespace std;

class node{
public:
    char data;
    node*children[26];
    bool terminal;
    int count;
    node(char d){
      data=d;
      terminal=false;
      count=0;
      for(int i=0;i<26;i++)
      children[i]=nullptr;
    }
};

class Trie{
public:
    node* root;
    Trie(){
      root=new node('\0');
    }
    void insert(string s){
      node* temp=root;
      for(int i=0;s[i]!='\0';i++){
        if(temp->children[s[i]-'a']!=nullptr){
          temp=temp->children[s[i]-'a'];
          temp->count++;
        }
        else{
          temp->children[s[i]-'a']=new node(s[i]);
          temp=temp->children[s[i]-'a'];
          temp->count++;
        }
      }
      temp->terminal=true;
    }
    bool search(string s){
      node*temp=root;
      for(int i=0;s[i]!='\0';i++){
        if(temp->children[s[i]-'a']==nullptr)
        return false;
        else
        temp=temp->children[s[i]-'a'];
      }
      return temp->terminal;
    }

};

string uniquePrefix(Trie t,string s){
      Node*temp=t.root;
      int i=0;
      int length=s.length();
      string ans="";
      while(i!=length){
        if(temp->children[s[i]]->cnt==1){
          ans=ans+s[i];
          return ans;
        }
        else{
          ans=ans+s[i];
          temp=temp->children[s[i]];
        }
        i++;
      }
      return "-1";
}

string longestPrefix(Trie t,string s,int n){
      node*temp=t.root;
      int length=s.length();
      string ans="";
      for(int i=0;s[i]!='\0';i++){
          if(temp->children[s[i]-'a']->count==n){
              ans+=s[i];
              temp=temp->children[s[i]-'a'];
          }
          else
          break;
      }

      return (ans=="")?"-1":ans;
}

int main(){


      Trie t;
      char words[][10]={"a","hello","not","news","apple"};
      char w[10];
      cin>>w;
      for(int i=0;i<5;i++)
      t.insert(words[i]);

      if(t.search(w))
      cout<<w<<" is present"<<endl;
      else
      cout<<w<<" is not present"<<endl;


      return 0;
}
