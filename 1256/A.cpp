/*Author- Koulick Sadhu*/
#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);8;
/* For counting number of digits, directly do floor(log10(n)+1)*/
using namespace std;
int main(){
        fio;
      ll T=1;
      cin>>T;
      while(T--){
        ll A,B,N,S,cc,zz;
        cin>>A>>B>>N>>S;
         cc=S/N; zz=S%N;
        if(zz>B || S>A*N+B){
            cout<<"NO"<<endl;continue;}


        cout<<"YES"<<endl;

     }
}