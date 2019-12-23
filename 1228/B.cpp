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
ll p(ll x,ll z){
    ll answer=1LL;
    for(;z;z>>=1,x=(x*x)%mod){
        if(z&1){
            answer=(answer*x)%mod;
        }
    }
    return answer%mod;
}
void solve(){
    ll h,w;
    cin>>h>>w;
    ll i,j;
    ll xx;
    ll r,c;
    vector<vector<ll> > arr(h+1,vector<ll>(w+1,0));
    for(r=0;r<h;r++)
    {
        cin>>xx;
        for(c=0;c<xx;c++)
        {
            arr[r][c]=1;
        }
        arr[r][xx]=-1;
    }
    for(c=0;c<w;c++)
    {
        cin>>xx;
        for(r=0;r<xx;r++)
        {
            if(arr[r][c]==1){
                    continue;
            }
            if(arr[r][c]==-1)
                {
                  cout<<0;
                  exit (0);
                }
		    arr[r][c]=1;
        }
        if(arr[xx][c]==1)
            {
                cout<<0;
                exit (0);
            }
     	arr[xx][c]=-1;
     }
        xx=0;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++){
                        xx=xx+(arr[i][j]==0);
            }
        }
        cout<<(p(2,xx));
}

int main() {
        fio;
        solve();
}