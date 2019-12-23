#include<bits/stdc++.h>
using namespace std;
// #include <boost/multiprecision/cpp_int.hpp> 
// using namespace boost::multiprecision;
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define ull unsigned long long int  // ranges from (0 - twice of long long int)
#define rep(i,a,n) for (ll i=a;i<n;i++)
#define per(i,n,a) for (ll i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
 
 
 
int main()
{
	boost;
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
	#endif
    //This is the Coding Block,Code Start From Here//
    	ll t=1;
        cin>>t;
        while(t--)
        {
            ll n; cin>>n;
            map<string,ll>mp;
            vector<string>vec;
            rep(i,0,n)
            {
                string st; cin>>st;
                vec.pb(st);
            }
            for(int i=0;i<vec.size();i++)
            {
                mp[vec[i]]++;
            }
            // now;
            vector<string>res;
            ll distinct=mp.size();
            cout<<n-distinct<<"\n"; // number of minimum steps;
 
            
            for(auto x: mp)
            {
                if(x.second==1)
                    cout<<x.first<<"\n";
                else
                {
                    cout<<x.first<<"\n";
                    string temp =x.first;
                    int end = temp[3];
                    ll a=x.second -1;
                    for(int i=0,j=0;i<a;)
                    {
                        
                        if(end!=j)
                            {
                                cout<<j<<temp[1]<<temp[2]<<temp[3]<<"\n";
                                i++; j++;
                            }
                        else
                            j++;
                    }
                }
            }
            
 
           
 
        }
        
 
        return 0;
 
}