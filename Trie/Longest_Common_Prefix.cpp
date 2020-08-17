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

string longestPrefix(Trie t,string s,int n){
      Node*temp=t.root;
      int length=s.length();
      string ans="";

      for(int i=0;s[i]!='\0';i++){
          if(temp->children[s[i]]->cnt==n){
              ans+=s[i];
              temp=temp->children[s[i]];
          }
          else
          break;
      }

      return ans;
}
int main(){


      Trie t;
      int n;
      cin>>n;
      string s[n];
     // cin.get();
      for(int i=0;i<n;i++){
        cin>>s[i];
        t.insert(s[i]);
      }

      cout<<longestPrefix(t,s[0],n)<<endl;



      return 0;
}
