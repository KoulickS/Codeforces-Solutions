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
bool isPrime(ll n)
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
void solve(ll A, ll B, ll C,ll D)
{
	ll kash = D/A;
    for (;kash*A>=0;kash--)
    {
    	ll hello=(D-(kash*A))%B;
    	ll v=(D-(kash*A))/B;
        if (hello==0&& (kash+v<=C))
        {
            cout<<kash<<" "<<(D-(kash*A))/B<<" "<<C-kash-(D-(kash*A))/B;
            return;
        }
    }
    cout << "-1";
}
int main()
{
    fio;
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    ll x=gcd(C,D);
    if(A*C<B || B%x){
        cout<<"-1"<<endl;
        exit(0);
    }
    if(B==0){
        cout<<"0"<<" "<<"0"<<" "<<A<<endl;
        exit(0);
    }
    solve(C,D,A,B);
}