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
const long long kot = LLONG_MAX;
#define pb emplace_back
#define pp pop_back
using kk = long double;
#define endl "\n"
#define rese(x,y) memset(x,y,sizeof(x))
#define f first
#define cc continue
#define S second
#define ee end
#define ss size
#define up upper_bound
#define eee endl
#define makeup make_pair
#define mod 1000000007
#define r reverse
#define bb back
#define CHARS_TOTAL 256
#define INT_BITS 32
const ll alpha=1e18;
/* For counting number of digits, directly do floor(log10(n)+1)*/
using namespace std;
ll n,freq[100100],ans[100100];
map <ll,ll> mp[100100];
vector <pair<ll,ll>> v;
set <int> s;
void solve(){
     cin>>n;
    for(ll i=0;i<n-2;i++)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        mp[x][y]++;
        mp[y][x]++;
        mp[x][z]++;
        mp[z][x]++;
        mp[y][z]++;
        mp[z][y]++;
        freq[x]++;
        freq[y]++;
        freq[z]++;
    }

    for(ll i=1;i<=n;i++)
    {
        if(freq[i] == 1 )
        {
            ans[1] = i;
            break;
        }
    }

    for(ll i=1;i<=n;i++)
    {
        if( freq[i] == 2 && mp[i][ans[1]] == 1 )
        {
            ans[2] = i;
            break;
        }
    }

    s.insert(ans[1]);
    s.insert(ans[2]);

    for(ll i=3;i<=n;i++)
    {
        v.clear();

        for(auto x:mp[ans[i-1]])
            v.push_back( { x.f,x.S } );

        for(auto x:v)
        {
            if( x.S == 2 && s.find(x.f) == s.end() )
            {
                s.insert(x.f);
                ans[i] = x.f;
                break;
            }
        }
    }

    for(ll i=1;i<=n;i++)
    {
        if( i != n )
            cout<<ans[i]<<" ";
        else
        {
            for(ll j=1;j<=n;j++)
                if( s.find(j) == s.end() )
                {
                    cout<<j<<" ";
                    break;
                }
        }
    }
}

int main()
{
    fio;
    solve();
}