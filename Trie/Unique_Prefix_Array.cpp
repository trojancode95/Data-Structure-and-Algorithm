#include<bits/stdc++.h>
using namespace std;

class Node{
public:
      char data;
      unordered_map<char,Node*>children;
      bool terminal;
      int cnt;
      Node(char d){
        data=d;
        terminal=false;
        cnt=0;
      }
};

class Trie{
    public:
      Node*root;
      Trie(){
        root=new Node('\0');
      }

      void insert(string s){
        Node*temp=root;
        for(int i=0;s[i]!='\0';i++){
          char ch=s[i];
          if(temp->children.count(ch)){
            temp=temp->children[ch];
            (temp->cnt)++;
          }
          else{
             Node*n=new Node(ch);
             temp->children[ch]=n;
             temp=n;
             (temp->cnt)++;
          }
        }
        temp->terminal=true;
      }
      bool find(string s){
        Node*temp=root;
        for(int i=0;s[i]!='\0';i++){
          char ch=s[i];
          if(temp->children.count(ch)==0)
          return false;
          else
          temp=temp->children[ch];
        }
        return temp->terminal;
      }
};

string prefix(Trie t,string s){
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
int main(){

      Trie t;
      int n;
      cin>>n;
      string s[n];
      cin.get();
      for(int i=0;i<n;i++){
        cin>>s[i];
        t.insert(s[i]);
      }

      for(int i=0;i<n;i++)
      cout<<prefix(t,s[i])<<endl;

      return 0;
}
