/*Author- Koulick Sadhu*/
#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_LIMIT 100010
#define haha(x) x.begin(),x.end()
#define rs resize
#define remove_zero(str) str.erase(0, str.find_first_not_of('0'));
#define b begin
const long long kot = LLONG_MAX;
#define pb emplace_back
#define pp pop_back
using kk = long double;
#define endl "\n"
#define rese(x,y) memset(x,y,sizeof(x))
#define f first
#define cc continue
#define s second
#define ee end
#define ii insert
#define ss size
#define up upper_bound
#define eee endl
#define mp make_pair
#define mod 1000000007
#define r reverse
#define bb back
#define CHARS_TOTAL 256
#define INT_BITS 32
const ll alpha=1e18;
/* For counting number of digits, directly do floor(log10(n)+1)*/
using namespace std;
void solve(){
       ll T;
       cin>>T;
       while(T--){
          ll a,b;
          cin>>a>>b;
          a=abs(a);
          b=abs(b);
          if(a>b){
            swap(a,b);
          }
          ll c=(b-a)%5;
          ll z=(b-a)/5 +c/2+c%2;
          cout<<z<<endl;
       }
}

int main()
{
    fio;
    solve();
}