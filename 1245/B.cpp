#include<bits/stdc++.h>
using namespace std;
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
//#define for(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp make_pair

void solve(vector<char>v,ll j,ll n){
       ll pp;
       pp=n/2;
       if(n&1)pp++;
       if(j>=pp){
        cout<<"YES\n";
        for(ll i=0;i<n;i++)cout<<v[i];
        cout<<"\n";
       }
       else cout<<"NO\n";

}

//ALWAYS USE ll DATA TYPE FOR INTEGER(FASTER THAN INTEGER AS WELL AS SOMETIMES WITHOUT USE LONG UR ANSWER WILL NOT ACCEPTED) && DOUBLE FOR DECIMAL VALUE
int main() {

    boost;
    ll t;
    cin>>t;
    while(t--)
    {
      ll n; cin>>n;
      ll a,b,c;
      cin>>a>>b>>c;
      string s; cin>>s;
      vector<char>r;
      for(ll i=0;i<n;i++){
            r.push_back('0');
      }
      ll count=0;
      for(int i=0;i<n;i++)
      {
            if(s[i]=='R')
            {
                  if(b-1>=0){
                        count++;
                        r[i]='P';
                        b--;
                  }
            }


            // for paper
            else if(s[i]=='P')
            {
                  if(c-1>=0){
                        count++;
                        r[i]='S';
                        c--;
                  }
            }



            // scissor
            else if(s[i]=='S')
            {
                  if(a-1>=0){
                        count++;
                        r[i]='R';
                        a--;
                  }
            }

      }
      for(ll i=0;i<n;i++){
            if(r[i]=='0'){
               if(a>=1)
               {
                   r[i]='R';
                   a--;
               }
               else if(b>=1){
                    b--;
                   r[i]='P';
               }
               else if(c>=1){
                c--;
                   r[i]='S';
               }
           }
      }
        solve(r,count,n);
    }
    return 0;
}