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
#define br break
const long long kot = LLONG_MAX;
#define pb emplace_back
#define pp pop_back
#define endl "\n"
#define f first
#define ee end
#define ii insert
#define up upper_bound
#define makeup make_pair
#define mod 1000000007
#define r reverse
#define bb back
#define CHARS_TOTAL 256
#define INT_BITS 32
const ll alpha=1e18;
/* For counting number of digits, directly do floor(log10(n)+1)*/
using namespace std;
int gcd(ll a, ll b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;

    // base case
    if (a == b)
        return a;

    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int largest(ll arr[], ll n)
{
    return *max_element(arr, arr+n);
}
// Function to return LCM of two numbers
 ll lcm(ll a, ll b)
 {
    return (a*b)/gcd(a, b);
 }

ll power(ll x, unsigned ll y, ll p)
{
    ll res = 1;      // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
class gfg
{
 public: int sumDigits(int no)
 {
   return no == 0 ? 0 : no%10 + sumDigits(no/10) ;
 }
};

void solve(){
      ll T=1;
      //cin>>T;
      while(T--){
         ll n;
         cin>>n;
         vector<ll>v(n);
         ll i;
         for(i=0;i<n;i++){
            cin>>v[i];
         }
         if(v[v.size()-1]==15){
            cout<<"DOWN"<<endl;
            return;
         }
         if(v[v.size()-1]==0){
            cout<<"UP"<<endl;
            return;
         }
         if(n==1){
            cout<<"-1"<<endl;
            return;
         }
         if(n>1){
            if(v[v.size()-2]>v[v.size()-1]){
                cout<<"DOWN"<<endl;
            }
            else{
                cout<<"UP"<<endl;
            }
         }
      }
}
int main()
{
    fio;
    solve();
}