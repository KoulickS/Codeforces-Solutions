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
void factors(ll n)
{
    // Print the number of 2s that divide n
    vector<ll>v;
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            v.pb(i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        v.pb(n);
}

int sumofdigits(ll n){
        ll sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
}
bool powertwo(ll x){
  return x&& (!(x&(x-1)));
}
void solve(){
      ll x=0,y,z,k;
      string str;
      cin>>str;
      vector<ll>vec;
      ll i;
      ll sz=str.size();
      for(i=0;i<sz;i++)
      {
          if(str[i]=='m' || str[i]=='w')
          {
              cout<<"0"<<endl;
              return;
          }
          if(str[i]=='u')
          {
              if(i>=1 && str[i-1]=='n')
              {
                  vec.pb(x);
              }
              if(i==0 || str[i-1]!='u')
              {
                  x=1;
              }
              else if(str[i-1]=='u')
              {
                  x++;
              }
          }
          else if(str[i]=='n')
          {
              if(i>=1 && str[i-1]=='u')
              {
                  vec.pb(x);
              }
              if(i==0 || str[i-1]!='n')
              {
                  x=1;
              }
              else if(str[i-1]=='n')
              {
                  x++;
              }
          }
          else if(i>=1 && (str[i-1]=='n'||str[i-1]=='u'))
          {
              vec.pb(x); x=0;
          }
          else
          {
            x=0;
          }
      }
      if(x)
      {
          vec.pb(x);
      }
          y=*max_element(haha(vec))+3;
          ll koulick=1;
          if(vec.size())
          {
             ll arr[y+1]={0}; arr[1]=1;
              for(i=2;i<y+1;i++)
              {
                  arr[i]=(arr[i-1]+arr[i-2])%mod;
              }
              for(auto it:vec)
              {
                  koulick=(koulick*arr[it+1])%mod;
              }
          }
          cout<<koulick<<endl;
  }
int main()
{
    fio;
    solve();
}