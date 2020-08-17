//String Matching : Whether a pattern is a substring of a String or not.
//Rabin Karp Algorithm is totally based on Rolling Hash Technique.
//Calculate the hash of Pattern and substring.
//If hash value of the substring and the pattern matches , then we double check that the whole characters of the pattern and the substring is matching or not.Because many substring can have the same hash value.Example :- abc ,bac, cab , bbb.... have the same hash value.
//So we designed a special hashing technique to calculate the value i.e Prime Number as our Base : We will multiply every character of a string with corresponding power of prime number.
//Still Worst Case Complexity of Rabin Karp Algorithm is O(n*m).
//Best Case Complexity is O(n+m).



#include<bits/stdc++.h>
using namespace std;
#define d 256

//Time Complexity :- O(length of string)
//hash value of abc :- a*d2 + b*d + c
int createHash(string str,int n,int q){

     int hash=0;
     for(int i=0;i<n;i++)
     hash=(hash*d+str[i])%q;

     return hash;
}

//Rabin Karp Algorithm
bool Rabin_Karp_Algorithm(string pat, string txt, int q)
{
     int m=txt.length();
     int n=pat.length();

	   int pathash=createHash(pat,n,q);
     int txthash=createHash(txt,n,q);

     int h=1;
     for(int i=0;i<n-1;i++)
     h=(h*d)%q;

     for(int i=0;i<=m-n;i++){
       if(pathash==txthash){
         int j;
         for(j=0;j<n;j++){
           if(txt[i+j]!=pat[j])
           break;
         }
         if(j==n)
         return true; // Here we can return the index also
       }

       if(i<m-n){
         txthash = (d*(txthash-h*txt[i])+txt[i+n])%q;
         if(txthash<0)
         txthash+=q;
       }
     }

     return false;
}

int main()
 {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	  int t;
    cin>>t;
    while(t--){
      string txt,pat;
      cin>>txt>>pat;
      int q=101;
      if(Rabin_Karp_Algorithm(pat,txt,q))
      cout<<"Yes"<<endl;
      else
      cout<<"No"<<endl;
    }
	  return 0;
}
