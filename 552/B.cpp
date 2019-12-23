#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_LIMIT 100000
#define pb push_back
#define bb back
#define mod 1000000007
#define f first
#define s second
#define CHARS_TOTAL 256
#define e endl
/* For counting number of digits, directly do floor(log10(n)+1)*/
using namespace std;

class gfg
{
 public : ll gcd(ll a, ll b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
 }


// Function to return LCM of two numbers
 ll lcm(ll a, ll b)
 {
    return (a*b)/gcd(a, b);
 }
} ;
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
void divisors(int n)
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

/*void factors(ll n)
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
    return v[0];
}
*/

int sumofdigits(ll n){
    ll c=0;
    while(n>0){
        c++;
        n/=10;
    }
    return c;
}

void solve(){
        ll n,sum=0;
        cin>>n;
        ll i;
        if(n<1e1){
            cout<<n<<endl;
        }
        else if(n<1e2){
            cout<<2*(n+1)-11<<endl;
        }
        else if(n<1e3){
            cout<<3*(n+1)-111<<endl;
        }
        else if(n<1e4){
            cout<<4*(n+1)-1111<<endl;
        }
        else if(n<1e5){
            cout<<5*(n+1)-11111<<endl;
        }
        else if(n<1e6){
            cout<<6*(n+1)-111111<<endl;
        }
        else if(n<1e7){
            cout<<7*(n+1)-1111111<<endl;
        }
        else if(n<1e8){
            cout<<8*(n+1)-11111111<<endl;
        }
        else if(n<1e9){
            cout<<9*(n+1)-111111111<<endl;
        }
        else if(n==1e9){
            cout<<10*(n+1)-1111111111<<endl;
        }
}
int main()
{
    fio;
    solve();
}