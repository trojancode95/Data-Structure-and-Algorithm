#include<bits/stdc++.h>
using namespace std;

void Naive_Search(string str,string pattern){
    for(int i=0;i<=str.size()-pattern.size();i++){
      int j;
      for(j=0;j<pattern.size();j++){
        if(str[i+j]!=pattern[j])
        break;
      }
      if(j==pattern.size())
      cout<<"Pattern is found at i = "<<i<<endl;
    }
}
int main()
 {
    string str,pattern;
    cin>>str>>pattern;

    Naive_Search(str,pattern);
	  return 0;
}
