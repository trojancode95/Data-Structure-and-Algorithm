#include<bits/stdc++.h>
using namespace std;

int longestSubstringLength(string s,int m){

     vector<int>prev(256,-1);
     int i=0,j,res;
     for(j=0;j<m;j++){
       i=max(i,prev[s[j]]+1);
       res=max(res,j-i+1);
       prev[s[j]]=j;
     }
     return res;
}



int main(){

     int t;
     cin>>t;
     while(t--){
        string s;
        cin>>s;
        int m=s.length();
        cout<<longestSubstringLength(s,m)<<endl;
     }

}
