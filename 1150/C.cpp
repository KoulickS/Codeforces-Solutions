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
using kk = long double;
#define endl "\n"
#define f first
#define cc continue
#define s second
#define ee end
#define ii insert
#define ss size
#define up upper_bound
#define mp make_pair
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
vector<ll>vec;
void mersennePrimes(ll n)
{
    // Create a boolean array "prime[0..n]"
    bool prime[n+1];

    // Generating primes using Sieve
    SieveOfEratosthenes(n,prime);

    // Generate all numbers of the form 2^k - 1
    // and smaller than or equal to n.
    for (ll k=2; ((1<<k)-1) <= n; k++)
    {
        ll num = (1<<k) - 1;

        // Checking whether number is prime and is
        // one less then the power of 2
        if (prime[num])
            vec.pb(num);
    }
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
    while (n % 2 == 0)
    {
        //cout << 2 << " ";
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            vec.pb(i);
            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        vec.pb(n);
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
unordered_map<string, int> lookup;

// Function to find the total number of distinct ways to get change of N
// from unlimited supply of coins in set S
int count(ll S[], ll n, ll N)
{
	// if total is 0, return 1 (solution found)
	if (N == 0)
		return 1;

	// return 0 (solution do not exist) if total become negative or
	// no elements are left
	if (N < 0 || n < 0)
		return 0;

	// construct a unique map key from dynamic elements of the input
	string key = to_string(n) + "|" + to_string(N);

	// if sub-problem is seen for the first time, solve it and
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// Case 1. include current coin S[n] in solution and recur
		// with remaining change (N - S[n]) with same number of coins
		int include = count(S, n, N - S[n]);

		// Case 2. exclude current coin S[n] from solution and recur
		// for remaining coins (n - 1)
		int exclude = count(S, n - 1, N);

		// assign total ways by including or excluding current coin
		lookup[key] = include + exclude;
	}

	// return solution to current sub-problem
	return lookup[key];
}

void solve(){
    ll T=1;
    //cin>>T;
    while(T--){
       ll n;
       cin>>n;
       ll one=0,two=0;
       ll i,x;
       for(i=0;i<n;i++){
           cin>>x;
           if(x==1){
               one++;
           }
           else{
             two++;
           }
       }
       if(two)
       {
           cout<<2<<" "; two--;
       }
       if(one){
           cout<<1<<" "; one--;
       }
       while(two){
            cout<<2<<" ";
            two--;
       }
       while(one){
            cout<<1<<" ";
            one--;
       }
    }
}

int main()
{
    fio;
    solve();
}