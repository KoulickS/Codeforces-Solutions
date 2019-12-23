#include <bits/stdc++.h>
#define FOR(x,a,b) for(int x=a;x<=b;x++)
#define FORD(x,a,b) for(int x=a;x>=b;x--)
#define maxn 100005
#define maxc 1000000007
#define reset(x,y) memset(x,y,sizeof(x))
#define task ""
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
#define remain(a,b) (a+b >= MOD) ? (a+b - MOD) : (a+b)
using namespace std;
int t,n,m,f[19][maxn];
vector<pii> v;
pii a[maxn];
int cur;
int ans = 0;
void init()
{
    for(int i=1; i<=18; i++)
        for(int j=1; j<=n; j++)
            f[i][j] = max(f[i-1][j], f[i-1][j+(1<<(i-1))]);
}
int getmax(int l, int r)
{
    int k = log2(r-l+1);
    return max(f[k][l], f[k][r-(1<<k)+1]);
}
bool check(int r)
{
    int len = r - cur + 1;
    int k = getmax(cur,r);
    pii x = {k,len};
    pii l = *lower_bound(v.begin(),v.end(),x);
    if(l.F >= k && l.S >= len) return true;
    return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    #endif
    cin >> t;
    while(t--)
    {
        int res = 0;
        reset(f,0);
        cin >> n;
        v.clear();
        for(int i=1; i<=n; i++) cin >> f[0][i];
        cin >> m;
        for(int i=1; i<=m; i++)
        {
            cin >> a[i].F >> a[i].S;
            v.pb(a[i]);
        }
        sort(v.begin(),v.end());
        init();
        cur = 1;
        bool ok = 1;
        while(cur <= n)
        {
            int l = cur;
            int r = n+1;
            while(l < r - 1)
            {
                int mid = (l+r)/2;
                if(check(mid)) l = mid;
                else r = mid;
            }
            if(!check(l))
            {
                ok = 0;
                res = -1;
                break;
            }
            cur = l + 1;
            res ++;
        }
        cout << res << '\n';
        cerr << res << '\n';
    }
}