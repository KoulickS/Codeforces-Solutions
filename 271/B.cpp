// C++ program to find
// maximum XOR subset
#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_LIMIT 100000
#define haha(x) x.begin(),x.end()
#define rs resize
#define b begin
#define pb emplace_back
#define endl "\n"
#define f first
#define ee end
#define ii insert
#define s second
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

int gcdofarray(vector<ll>v, ll n)
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
int ar[100006]={0};
int ans[100006];
int matrix[505][505];
void sieve()
{
    int i,j,prime;
    ar[1]=1;
    ar[2]=0;
    for(i=4;i<=100004;i=i+2)
        ar[i]=1;

    for(i=3;i*i<=100004;i=i+2)
    {
       if(ar[i]==0)
       for(j=i*i;j<=100004;j=j+2*i)
       {
           ar[j]=1;
       }
    }

    for(i=100003;i>=0;i--)
    {
        if(ar[i]==0)
        {
            prime=i;
        }
        ans[i]=prime;

    }
}

int main()
{
    int t,n,temp,t1,t2,t3,num,i,j,m;
    sieve();
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&num);
            matrix[i][j]=ans[num]-num;
        }
    }
    int min1=INT_MAX;
    for(i=0;i<n;i++)
    {
        int sum=0;
        for(j=0;j<m;j++)
        {
            sum=sum+matrix[i][j];
        }
        if(sum<min1)
            min1=sum;
    }

        for(j=0;j<m;j++)
        {
            int sum=0;
            for(i=0;i<n;i++)
            {
                sum=sum+matrix[i][j];
            }
            if(sum<min1)
                min1=sum;
        }

    cout<<min1<<"\n";
    return 0;
}