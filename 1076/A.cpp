#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_LIMIT 100000
#define pb push_back
#define mod 1000000007
#define bb back
#define CHARS_TOTAL 256
#define e endl
#define pi 3.1415926
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

 int countGCD(ll L, ll R, ll g)
{
    // Setting the value of L, R.
    L = (L + g - 1) / g;
    R = R/ g;

    // For each possible pair check if GCD is 1.
    ll ans = 0;
    for (ll i = L; i <= R; i++)
        for (ll j = L; j <= R; j++)
            if (gcd(i, j) == 1)
                ans++;

    return ans;
}


ll power(ll x, unsigned ll y)  //Power in O(logn)
{
    ll temp;
    if(y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
    {
        if(y > 0)
            return x * temp * temp;
        else
            return (temp * temp) / x;
    }
}
bool comp(int a, int b)
{
    return (a < b);
}
void SieveOfEratosthenes(ll n, bool prime[],
                         bool primesquare[], ll a[])
{
    // Create a boolean array "prime[0..n]" and
    // initialize all entries it as true. A value
    // in prime[i] will finally be false if i is
    // Not a prime, else true.
    for (ll i = 2; i <= n; i++)
        prime[i] = true;

    // Create a boolean array "primesquare[0..n*n+1]"
    // and initialize all entries it as false. A value
    // in squareprime[i] will finally be true if i is
    // square of prime, else false.
    for (ll i = 0; i <= (n * n + 1); i++)
        primesquare[i] = false;

    // 1 is not a prime number
    prime[1] = false;

    for (ll p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then
        // it is a prime
        if (prime[p] == true) {
            // Update all multiples of p
            for (ll i = p * 2; i <= n; i += p)
                prime[i] = false;
        }
    }

    int j = 0;
    for (ll p = 2; p <= n; p++) {
        if (prime[p]) {
            // Storing primes in an array
            a[j] = p;

            // Update value in primesquare[p*p],
            // if p is prime.
            primesquare[p * p] = true;
            j++;
        }
    }
}

// Function to count divisors
int countDivisors(ll n)
{
    // If number is 1, then it will have only 1
    // as a factor. So, total factors will be 1.
    if (n == 1)
        return 1;

    bool prime[n + 1], primesquare[n * n + 1];

    ll a[n]; // for storing primes upto n

    // Calling SieveOfEratosthenes to store prime
    // factors of n and to store square of prime
    // factors of n
    SieveOfEratosthenes(n, prime, primesquare, a);

    // ans will contain total number of distinct
    // divisors
    ll ans = 1;

    // Loop for counting factors of n
    for (ll i = 0;; i++) {
        // a[i] is not less than cube root n
        if (a[i] * a[i] * a[i] > n)
            break;

        // Calculating power of a[i] in n.
        ll cnt = 1; // cnt is power of prime a[i] in n.
        while (n % a[i] == 0) // if a[i] is a factor of n
        {
            n = n / a[i];
            cnt = cnt + 1; // incrementing power
        }

        // Calculating number of divisors
        // If n = a^p * b^q then total divisors of n
        // are (p+1)*(q+1)
        ans = ans * cnt;
    }

    // if a[i] is greater than cube root of n

    // First case
    if (prime[n])
        ans = ans * 2;

    // Second case
    else if (primesquare[n])
        ans = ans * 3;

    // Third casse
    else if (n != 1)
        ans = ans * 4;

    return ans; // Total divisors
}
bool prime(ll n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (ll i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}
int printPrime(ll n)
{
    ll c=0;
    for (ll i =1; i <= n; i++) {
        if (prime(i))
            c++;
    }
    return c;
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
bool powertwo(ll x){
  return x&& (!(x&(x-1)));
}
bool ans(ll arr[], ll i, ll r){
	if(i>4){
        return false;
	}
	if(r==0 && i<=4){
        return true;
	}
	else{
        return ans(arr, i+1, r-arr[i]) || ans(arr, i+1, r);
	}
}

int abc(ll n){
    ll i,c=0;
    for(i=1;i<=n;i++){
        if(gcd(i,n)==1){
            c++;
        }
    }
    return c;
}
ll n;
string s, ank="";
void solve(){
            cin>>n>>s;
	for(int i=0;i+1<n;i++)
	{
		if(s[i]>s[i+1])
		{
			for(int j=i+1;j<n;j++)
				ank+=s[j];
			break;
		}
		else
			ank+=s[i];
	}
	cout<<ank;
}
int main()
{
    fio;
    solve();
}