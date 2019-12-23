#include<bits/stdc++.h>
#include<string.h>
#define ll long long int
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_LIMIT 10000000
#define haha(x) x.begin(),x.end()
#define rs resize
#define remove_zero(str) str.erase(0, str.find_first_not_of('0'));
#define br break
const long long kot = LLONG_MAX;
#define pb emplace_back
#define pp pop_back
using kk = long double;
#define endl "\n"
#define rese(x,y) memset(x,y,sizeof(x))
#define f first
#define ul unsigned long
#define cc continue
#define ee end
#define ii insert
#define mo 1000000007
#define ss size
#define up upper_bound
#define pc pop_back()
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

void sieve(bool primes[], int x)
{
    primes[1] = false;
    for (int i=2; i*i <= x; i++)
    {
        if (primes[i] == true)
        {
            for (int j=2; j*i <= x; j++)
                primes[i*j] = false;
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
vector<ll>ve;
void divisors(ll n)
{
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                ve.pb(i);

            else // Otherwise print both
            ve.pb(i);
            ve.pb(n/i);
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
   for (ll i=str.length()-1; i>=0; i--)
      cout << str[i];
}
struct Node
{
    int key;
    struct Node *left, *right;
};
Node *newNode(ll key)
{
    Node *temp = new Node;
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}
void createNode(ll parent[], ll i, Node *created[], Node **root)
{
    if (created[i] != NULL)
        return;
    created[i] = newNode(i);
    if (parent[i] == -1)
    {
        *root = created[i];
        return;
    }

    // If parent is not created, then create parent first
    if (created[parent[i]] == NULL)
        createNode(parent, parent[i], created, root);

    // Find parent pointer
    Node *p = created[parent[i]];

    // If this is first child of parent
    if (p->left == NULL)
        p->left = created[i];
    else // If second child
        p->right = created[i];
}

// Creates tree from parent[0..n-1] and returns root of the created tree
Node *createTree(ll parent[], ll n)
{
    Node *created[n];
    for (ll i=0; i<n; i++)
        created[i] = NULL;

    Node *root = NULL;
    for (ll i=0; i<n; i++)
        createNode(parent, i, created, &root);

    return root;
}
// Utility function to do inorder traversal
ll inorder(Node *root)
{
    ll c=0,d=0;
    if (root != NULL)
    {
        c=inorder(root->left);

        //cout << root->key << " ";
        d=inorder(root->right);
    }
    if(d==c){
        return 1;
    }
    else if(d>c){
        return 2;
    }
    else{
        return 3;
    }
}
/*https://www.geeksforgeeks.org/queries-of-ncrp-in-o1-time-complexity/*/
const int N=1000001;
ll factorialNumInverse[N + 1];
ll naturalNumInverse[N + 1];
ll fact[N + 1];
void InverseofNumber(ll p)
{
    naturalNumInverse[0] = naturalNumInverse[1] = 1;
    for (int i = 2; i <= N; i++)
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p;
}
void InverseofFactorial(ll p)
{
    factorialNumInverse[0] = factorialNumInverse[1] = 1;
    for(ll i = 2; i <= N; i++)
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p;
}
void factorial(ll p)
{
    fact[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % p;
    }
}
ll kash(ll N, ll R, ll p)
{
    ll ans=((fact[N] * factorialNumInverse[R])%p*factorialNumInverse[N-R])% p;
    return ans;
}
void solve(){
    ll t;
    cin>>t;
    ll p=1e9+7;
    InverseofNumber(p);
    InverseofFactorial(p);
    factorial(p);
    while(t--){
        string str;
        cin>>str;
        reverse(str.begin(),str.end());
        if(str[0]=='o' && str[1]=='p'){
            cout<<"FILIPINO"<<endl;
        }
        else if(str[0]=='u' && str[1]=='s' && str[2]=='e' && str[3]=='d'){
            cout<<"JAPANESE"<<endl;
        }
        else if(str[0]=='u' && str[1]=='s' && str[2]=='a' && str[3]=='m'){
            cout<<"JAPANESE"<<endl;
        }
        else if(str[0]=='a' && str[1]=='d' && str[2]=='i' && str[3]=='n' && str[4]=='m'){
            cout<<"KOREAN"<<endl;
        }
    }
}
int main()
{
    fio;
    solve();
}