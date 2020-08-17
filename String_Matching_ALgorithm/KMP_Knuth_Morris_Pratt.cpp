// Example:
// Input:
// 2
// aabaacaadaabaaba
// aaaab
// aabaacaadaabaaba
// caada
// Output:
// No
// Yes


#include<bits/stdc++.h>
using namespace std;


//Preprocessing the length of longest prefix suffix array i.e lps Array
void computeLPSArray(string pat, int m, int* lps){

      lps[0]=0;
      int len=0;
      int i=1;
      while(i<m){
        if(pat[i]==pat[len]){
          len++;
          lps[i]=len;
          i++;
        }
        else{
          if(len==0){
            lps[i]=0;
            i++;
          }
          else
          len=lps[len-1]; //Also Note that we do not increment i here
        }
      }
    //len is the longest length of prefix suffix present in any string.
}

//Implementation of KMP pattern searching algorithm
bool KMPSearch(string pat, string txt) {
      int m=pat.length();
      int n=txt.length();

      int lps[m];
      // Preprocess the pattern (calculate lps[] array)
      computeLPSArray(pat,m,lps);

      int i=0,j=0;
      while(i<n){
        if(txt[i]==pat[j]){
          i++;
          j++;
        }
        if(j==m){
        //To check if more further substring and pattern matches or not, we do j=lps[j-1];
        //the index where the both substring and pattern matches is (i-j).
        return true;
        }
        else if(i<n && pat[j]!=txt[i]){
          if(j==0)
          i++;
          else
          j=lps[j-1];
        }
      }
      return false;
}

int main(){

      int t;
      cin>>t;
      while(t--){
        string txt,pat;
        cin>>txt>>pat;
        if(KMPSearch(pat,txt))
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
      }
      return 0;
}
