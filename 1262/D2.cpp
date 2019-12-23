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
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
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
#define ip insert
#define ss size
#define up upper_bound
#define mp make_pair
#define mod 1000000007
#define r reverse
#define bb back
#define CHARS_TOTAL 256
#define INT_BITS 32
using namespace __gnu_pbds;
const ll alpha=1e18;
/* For counting number of digits, directly do floor(log10(n)+1)*/
using namespace std;
typedef tree<pair<int,int>,null_type,
less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>// https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
ordered_set;
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
ordered_set sp;  //https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/
int largest(ll arr[], ll n)
{
    return *max_element(arr, arr+n);
}
// Function to return LCM of two numbers
 ll lcm(ll a, ll b)
 {
    return (a*b)/gcd(a, b);
 }

 void SieveOfEratosthenes(ll n, bool prime[])
{
    // Initialize all entries of boolean array
    // as true. A value in prime[i] will finally
    // be false if i is Not a prime, else true
    // bool prime[n+1];
    for (ll i=0; i<=n; i++)
        prime[i] = true;

    for (ll p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it
        // is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (ll i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

// Function to generate mersenne primes less
// than or equal to n


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


bool isPerfectSquare(long double x)
{
  // Find floating point value of
  // square root of x.
  long double sr = sqrt(x);

  // If square root is an integer
  return ((sr - floor(sr)) == 0);
}


bool comp(int a, int b)
{
    return (a < b);
}
void divisors(ll n)
{
    vector<ll>v;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                v.pb(i);

            else // Otherwise print both
            v.pb(i);
            v.pb(n/i);
        }
    }
}
bool isPrime(ll n) {

    if (n == 1) {
        return false;
    }

    ll i = 2;

    while (i*i <= n) {

        if (n % i == 0) {
             return false;
        }
        i += 1;
    }
    return true;
}

int gcdofarray(ll v[], ll n)
{
    ll result = v[0];
    for (ll i = 1; i < n; i++)
        result = gcd(v[i], result);
    return result;
}

int sumofdigits(ll n){
        ll sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
}
ll kash(ll n){
   if(n>0) return n;
   else return -n;
}
bool powertwo(ll x){
  return x&& (!(x&(x-1)));
}

ll finduncommonsubsequence(string str,string s){
    if(!str.compare(s)){
        return 0;
    }
    return max(str.length(),s.length());
}
void reversec(string str)
{
   for (int i=str.length()-1; i>=0; i--)
      cout << str[i];
}
bool compare(pair<ll,ll>p,pair<ll,ll>g)  //Taken from GeeksforGeeks
{
    if(p.first!=g.first)
    {
        return p.first>g.first;
    }
    return p.second<g.second;
}
vector<ll>vec;
ll N;
ordered_set s;
ll M; vector<pair<ll,ll>>vp;
void solve(){
          cin>>N; vec.resize(N);
          ll i;
          for(i=0;i<N;i++)
          {
              cin>>vec[i]; vp.pb(vec[i],i);
          }
          ll ii=0;
          ll c=1;
          sort(vp.b(),vp.ee(),compare); cin>>M;
          vector<pair<pair<ll,ll>,ll>>vv(M); vector<ll>koulick(M);
          for(i=0;i<M;i++){ cin>>vv[i].first.first>>vv[i].first.second, vv[i].second=i; }
          sort(vv.b(),vv.ee());
          for(auto& i:vp)
          {
              sp.ip({i.second,i.first});
              while(ii<M && vv[ii].first.first==c)
              {
                  koulick[vv[ii].second]=(*sp.find_by_order(vv[ii].first.second-1)).second; ii++;
              }
              c++;
          }
          for(ll i:koulick)
          {
              cout<<i<<endl;
          }
}

int main()
{
    fio;
    solve();
}